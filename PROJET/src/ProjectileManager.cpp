#include "ProjectileManager.h"
#include <iostream>
   
ProjectileManager::ProjectileManager(){}

void ProjectileManager::addProjectile(std::unique_ptr<Projectile> projectile) {
    projectiles.push_back(std::move(projectile));
}

void ProjectileManager::removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove) {
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [&projectileToRemove](const std::unique_ptr<Projectile>& projectile) {
            return projectile.get() == projectileToRemove.get();
        }), projectiles.end());
}

bool ProjectileManager::isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile) const {
    return (projectile->getPos().x < 0 || projectile->getPos().x > Display::getDIMW() ||
            projectile->getPos().y < 0 || projectile->getPos().y > Display::getDIMH());
}

bool ProjectileManager::hasProjectileCollided( Player* playerPtr=nullptr, std::vector<Invader> *invaders=nullptr) {
    for (auto& projectilePtr : projectiles) { 
        // Check collision with an invader
        if (invaders != nullptr){
            for ( auto& invaderPtr : *invaders)  {
                Position Iposition = invaderPtr.getPos();
                if ((projectilePtr->getPos().x >= Iposition.x) && (projectilePtr->getPos().x <= Iposition.x + invaderPtr.getWidth()) &&
                    (projectilePtr->getPos().y >= Iposition.y) && (projectilePtr->getPos().y <= Iposition.y + invaderPtr.getHeight())) {
                    //ici on appelel damagetakenprojectile avec l'invaderptr
                    DamageTakenProjectile(nullptr,&invaderPtr);
                }
            }
        }
        // Check collision with a player
        if (playerPtr != nullptr) {
            Position Pposition = playerPtr->getPos();
            if ((projectilePtr->getPos().x >= Pposition.x) && (projectilePtr->getPos().x <= Pposition.x + playerPtr->getWidth()) &&
                (projectilePtr->getPos().y >= Pposition.y) && (projectilePtr->getPos().y <= Pposition.y + playerPtr->getHeight())) {
                // Ici, on appelle damagetakenprojectile avec le playerptr
                DamageTakenProjectile(playerPtr,nullptr);
            }
        }
        return false;
    }
}

//Une fonction pour le player et l'invader : on l'appelle comme ça :  DamageTakenProjectile(hit,true,playerPtr,nullptr) ou DamageTakenProjectile(hit,true,nullptr,invaderPtr)
void ProjectileManager::DamageTakenProjectile(Player* playerPtr = nullptr, Invader* invaderPtr = nullptr) {
    for (const auto& projectilePtr : projectiles) {
        int dmg = projectilePtr->getDamage();
        if (playerPtr != nullptr) {
            playerPtr->setHP(playerPtr->getHP() - dmg);
            removeProjectile(projectilePtr);
            if(playerPtr -> HPnullPlayership()) {}
        } else if (invaderPtr != nullptr) {
            invaderPtr->setHP(invaderPtr->getHP() - dmg);
            removeProjectile(projectilePtr);
            if(invaderPtr -> HPnullInvader())
            {
                invaderPtr -> setHP(100);
                //invaders.erase(invaders.begin()+i);
                std::cout<<"Invader mort"<<std::endl;;
            }
        
        }
    }
}


void ProjectileManager::DrawProj(SDL_Renderer* renderer)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
            (*it)->drawProjectile(renderer);
        }
}


void ProjectileManager::UpdateProj() {
    for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
            (*it)->update();
    }
    // Remove any out-of-bounds projectiles here
}