#include "ProjectileManager.h"
   
ProjectileManager::ProjectileManager() {
    this->nbP = 0;
    
}


void ProjectileManager::SetnbProjectile(int nb){
    this->nbP = nb ;
}
int ProjectileManager::GetnbProjectile(){
    return nbP;
}

void ProjectileManager::addProjectile(std::unique_ptr<Projectile> projectile) {
    projectiles.push_back(std::move(projectile));
}

void ProjectileManager::removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove) {
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [&projectileToRemove](const std::unique_ptr<Projectile>& projectile) {
            return projectile.get() == projectileToRemove.get();
        }), projectiles.end());
}

bool ProjectileManager::isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile) {
    return (projectile->getPos().x < 0 || projectile->getPos().x > Display::getDIMW() ||
            projectile->getPos().y < 0 || projectile->getPos().y > Display::getDIMH());
}

bool ProjectileManager::hasProjectileCollided(const std::unique_ptr<Projectile>& projectile, Player* playerPtr = nullptr, Invader* invaderPtr = nullptr) {
    if (invaderPtr != nullptr){
        Position Iposition = invaderPtr->getPos();
        if ( (projectile->getPos().x >= Iposition.x)  && (projectile->getPos().x <= Iposition.x+invaderPtr->getWidth())  && (projectile->getPos().y >= Iposition.y)  && (projectile->getPos().y <= Iposition.y+invaderPtr->getHeight()) ) {
            return true;
        } else {return false;}
    }
    if (playerPtr != nullptr){
        Position Pposition = playerPtr->getPos();
        if ( (projectile->getPos().x >= Pposition.x)  && (projectile->getPos().x <= Pposition.x+playerPtr->getWidth())  && (projectile->getPos().y >= Pposition.y)  && (projectile->getPos().y <= Pposition.y+playerPtr->getHeight()) ) {
            return true;
        } else {return false;}
        }
    return false;
}

//Une fonction pour le player et l'invader : on l'appelle comme ça :  DamageTakenProjectile(hit,true,playerPtr,nullptr) ou DamageTakenProjectile(hit,true,nullptr,invaderPtr)
void ProjectileManager::DamageTakenProjectile(bool hit, bool isPlayer, Player* playerPtr = nullptr, Invader* invaderPtr = nullptr) {
    for (const auto& projectilePtr : projectiles) {
        int dmg = projectilePtr->getDamage();
        if (isPlayer && playerPtr != nullptr) {
            playerPtr->setHP(playerPtr->getHP() - dmg);
            removeProjectile(projectilePtr);
        } else if (!isPlayer && invaderPtr != nullptr) {
            invaderPtr->setHP(invaderPtr->getHP() - dmg);
            removeProjectile(projectilePtr);
        }
    }
}


void ProjectileManager::DrawProj(SDL_Renderer* renderer)
{
    for(int i=0;i<nbP;i++)
    {
        projectiles[i]->drawProjectile(renderer);
    }
}


void ProjectileManager::UpdateProj()
{
    for(int i=0;i<nbP;i++)
    {
        projectiles[i]->update();
    }
}