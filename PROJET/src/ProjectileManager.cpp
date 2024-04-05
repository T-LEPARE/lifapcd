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

void ProjectileManager::hasProjectileCollided( Player* playerPtr=nullptr, std::vector<Invader> *invaders=nullptr) {
    for (auto& projectilePtr : projectiles) { 
        // Check collision with an invader
        if (invaders != nullptr){
            for ( auto& invaderPtr : *invaders)  {
                Position Iposition = invaderPtr.getPos();
                if ((projectilePtr->getPos().x >= Iposition.x) && (projectilePtr->getPos().x <= Iposition.x + invaderPtr.getWidth()) &&
                    (projectilePtr->getPos().y >= Iposition.y) && (projectilePtr->getPos().y <= Iposition.y + invaderPtr.getHeight())) {
                    //ici on appelel damagetakenprojectile avec l'invaderptr
                    DamageTakenProjectile(move(projectilePtr),nullptr,&invaderPtr);
                    
                }
            }
        }
        // Check collision with a player
        if (playerPtr != nullptr) {
            Position Pposition = playerPtr->getPos();
            if ((projectilePtr->getPos().x >= Pposition.x) && (projectilePtr->getPos().x <= Pposition.x + playerPtr->getWidth()) &&
                (projectilePtr->getPos().y >= Pposition.y) && (projectilePtr->getPos().y <= Pposition.y + playerPtr->getHeight())) {
                // Ici, on appelle damagetakenprojectile avec le playerptr
                DamageTakenProjectile(move(projectilePtr),playerPtr,nullptr);
            }
        }

    }
}

void ProjectileManager::DamageTakenProjectile(std::unique_ptr<Projectile> projectilePtr, Player* playerPtr, Invader* invaderPtr) {
    int dmg = projectilePtr->getDamage();
        if (playerPtr != nullptr) {
            playerPtr->setHP(playerPtr->getHP() - dmg);
            //it = projectiles.erase(it); // Remove projectile from projectiles vector
        } else if (invaderPtr != nullptr) {
            invaderPtr->setHP(invaderPtr->getHP() - dmg);;
            //it = projectiles.erase(it); // Remove projectile from projectiles vector
        }
    // Clear projectilesToRemove vector after processing all projectiles
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
    // On supprime les projectiles ici si nécessaire
}