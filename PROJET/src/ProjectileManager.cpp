#include "ProjectileManager.h"
#include <iostream>
#include <algorithm> // for std::copy_if

ProjectileManager::ProjectileManager() {}

void ProjectileManager::addProjectile(std::unique_ptr<Projectile> projectile) {
  if (projectile != nullptr) {
    projectiles.push_back(std::move(projectile));
  }
}

void ProjectileManager::removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove) {
  projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                 [&projectileToRemove](const std::unique_ptr<Projectile>& projectile) {
                                   return projectile.get() == projectileToRemove.get();
                                 }),
                   projectiles.end());
}

bool ProjectileManager::isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile) const {
  if (projectile == nullptr) {
    return false; // Avoid null pointer access here
  }
  return (projectile->getPos().x < 0 || projectile->getPos().x > Display::getDIMW() ||
          projectile->getPos().y < 0 || projectile->getPos().y > Display::getDIMH());
}

void ProjectileManager::hasProjectileCollided(Player* playerPtr, std::vector<Invader>* invaders) {
  for (auto it = projectiles.begin(); it != projectiles.end();) {
    if (*it != nullptr) { // Check for null pointer before using
      // Check collision with invader
      if (invaders != nullptr) {
        for (auto& invaderPtr : *invaders) {
          Position Iposition = invaderPtr.getPos();
          if (((*it)->getPos().x >= Iposition.x) &&
              ((*it)->getPos().x <= Iposition.x + invaderPtr.getWidth()) &&
              ((*it)->getPos().y >= Iposition.y) &&
              ((*it)->getPos().y <= Iposition.y + invaderPtr.getHeight())) {
            DamageTakenProjectile(*it, nullptr, &invaderPtr);
            break; // Projectile can only collide with one invader, exit inner loop
          }
        }
      }

      // Check collision with player
      if (playerPtr != nullptr) {
        Position Pposition = playerPtr->getPos();
        if (((*it)->getPos().x >= Pposition.x) &&
            ((*it)->getPos().x <= Pposition.x + playerPtr->getWidth()) &&
            ((*it)->getPos().y >= Pposition.y) &&
            ((*it)->getPos().y <= Pposition.y + playerPtr->getHeight())) {
          DamageTakenProjectile(*it, playerPtr, nullptr);
        }
      }
      ++it;
    }  else {
        it = projectiles.erase(it); // Erase invalid projectile and update iterator
        }
    }
  }

void ProjectileManager::DamageTakenProjectile(std::unique_ptr<Projectile>& projectilePtr, Player* playerPtr, Invader* invaderPtr) {
  if (projectilePtr == nullptr) {
    exit(EXIT_FAILURE); // Avoid using null pointer
  }
  int dmg = projectilePtr->getDamage();
  if (playerPtr != nullptr) {
    playerPtr->setHP(playerPtr->getHP() - dmg);
    std::cout << "playerHP = " << playerPtr->getHP() << std::endl;
  } else if (invaderPtr != nullptr) {
    invaderPtr->setHP(invaderPtr->getHP() - dmg);
    std::cout << "invaderHP = " << invaderPtr->getHP() << std::endl;
  }
  removeProjectile(projectilePtr);
}

void ProjectileManager::DrawProj(SDL_Renderer* renderer) {
  for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
    if (*it != nullptr) { // Check for null pointer before using
      (*it)->drawProjectile(renderer);
    }
  }
}

void ProjectileManager::UpdateProj() {
  for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
    if (*it != nullptr) {
      (*it)->update();
      if (isProjectileOutOfBounds(*it)) {
        removeProjectile(*it);
      }
    }
  }
}