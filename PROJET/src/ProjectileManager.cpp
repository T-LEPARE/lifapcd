#include "ProjectileManager.h"
#include <iostream>
#include <algorithm>

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
    return false;
  }
  return (projectile->getPos().x < 0 || projectile->getPos().x > Display::getDIMW() ||
          projectile->getPos().y < 0 || projectile->getPos().y > Display::getDIMH());
}

void ProjectileManager::hasProjectileCollided(Player* playerPtr, std::vector<Invader>* invaders) {
  projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                 [](const std::unique_ptr<Projectile>& projectile) {
                                     return projectile == nullptr;
                                 }),
                  projectiles.end());
  for (auto it = projectiles.begin(); it != projectiles.end();) {
      // Check collision with invader
      if (invaders != nullptr) {
        for (auto& invaderPtr : *invaders) {
          Position Iposition = invaderPtr.getPos();
          if (((*it)->getPos().x >= Iposition.x) &&
              ((*it)->getPos().x <= Iposition.x + invaderPtr.getWidth()) &&
              ((*it)->getPos().y >= Iposition.y) &&
              ((*it)->getPos().y <= Iposition.y + invaderPtr.getHeight())) {
            DamageTakenProjectile(*it, nullptr, &invaderPtr);
            break;
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
  }
}

void ProjectileManager::DamageTakenProjectile(std::unique_ptr<Projectile>& projectilePtr, Player* playerPtr, Invader* invaderPtr) {
  if (projectilePtr == nullptr) {
    std::cout << "Error: Projectile pointer is null!" << std::endl;
    exit(EXIT_FAILURE);
  }
  int dmg = projectilePtr->getDamage();
  if (playerPtr != nullptr) {
    playerPtr->setHP(playerPtr->getHP() - dmg);
    std::cout << "playerHP = " << playerPtr->getHP() << std::endl;
  } else if (invaderPtr != nullptr) {
    invaderPtr->setHP(invaderPtr->getHP() - dmg);
    std::cout << "invaderHP = " << invaderPtr->getHP() << std::endl;
  }
}

void ProjectileManager::DrawProj(SDL_Renderer* renderer) {
  for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
    if (*it != nullptr) { // Check for null pointer before using
      (*it)->drawProjectile(renderer);
    }
  }
}

void ProjectileManager::UpdateProj() {
  for (auto it = projectiles.begin(); it != projectiles.end();) {
    if (*it != nullptr) {
      (*it)->update();
      if (isProjectileOutOfBounds(*it)) {
        removeProjectile(*it);
      }else{++it;}
    }
  }
}

void ProjectileManager::clearTab() {
  projectiles.clear();
}