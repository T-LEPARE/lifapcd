#include "ProjectileManager.h"
#include <iostream>
#include <algorithm>

ProjectileManager::ProjectileManager() {}

ProjectileManager::~ProjectileManager() {
      projectiles.clear();
}

void ProjectileManager::addProjectile(std::unique_ptr<Projectile> projectile) {
  if (projectile != nullptr) {
    projectiles.push_back(std::move(projectile));
  }
}

void ProjectileManager::removeProjectiles(const std::unique_ptr<Projectile>& projectileToRemove) {
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

void ProjectileManager::hasProjectileCollided(Player* playerPtr, std::vector<Invader>* invaders,  Mix_Chunk* SoundDmg) {

  //erase all nullptr from the vector before everything... It fixed a crash
  projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                 [](const std::unique_ptr<Projectile>& projectile) {
                                     return projectile == nullptr;
                                 }),
                  projectiles.end());
  
  std::vector<size_t> indicesToRemove; // Indices of projectiles to remove

  for (size_t i = 0; i < projectiles.size(); ++i) {
      bool collided = false;

      // Check collision with invader
      if (invaders != nullptr) {
        for (auto& invaderPtr : *invaders) {
          Position Iposition = invaderPtr.getPos();
          if ((projectiles[i]->getPos().x >= Iposition.x) &&
              (projectiles[i]->getPos().x <= Iposition.x + invaderPtr.getWidth()) &&
              (projectiles[i]->getPos().y >= Iposition.y) &&
              (projectiles[i]->getPos().y <= Iposition.y + invaderPtr.getHeight())) {
            DamageTakenProjectile(projectiles[i], nullptr, &invaderPtr);
            collided = true;
            break;
          }
        }
      }
      // Check collision with player
      if (!collided && playerPtr != nullptr) {
        Position Pposition = playerPtr->getPos();
        if ((projectiles[i]->getPos().x >= Pposition.x) &&
            (projectiles[i]->getPos().x <= Pposition.x + playerPtr->getWidth()) &&
            (projectiles[i]->getPos().y >= Pposition.y) &&
            (projectiles[i]->getPos().y <= Pposition.y + playerPtr->getHeight())) {
          Mix_PlayChannel(-1, SoundDmg, 0); 
          DamageTakenProjectile(projectiles[i], playerPtr, nullptr);
          collided = true;
        }
      }
      //if projectile collided, mark it for removal
      if (collided) {
        indicesToRemove.push_back(i);
      }
  }
  //remove all projectiles marked for removal
  for (auto it = indicesToRemove.begin(); it != indicesToRemove.end(); ++it) {
    projectiles.erase(projectiles.begin() + *it);
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
      if((*it)->getProvenaceDuTir())
        (*it)->drawProjectilePlayer(renderer);
      else (*it)->drawProjectileInvader(renderer);
    }
  }
}

void ProjectileManager::UpdateProj() {
  for (auto it = projectiles.begin(); it != projectiles.end();) {
    if (*it != nullptr) {
      (*it)->update();
      if (isProjectileOutOfBounds(*it)) {
        removeProjectiles(*it);
      }else{++it;}
    }
  }
}

void ProjectileManager::clearTab() {
  projectiles.clear();
}

const std::vector<std::unique_ptr<Projectile>>& ProjectileManager::getProjectiles() const {
  return projectiles;
}