#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Playership.h"
#include "Invaders.h"
#include "StarblitzGameDisplay.h"



class Player;
class ProjectileManager {
    private:
    std::vector<std::unique_ptr<Projectile>> projectiles;
    int nbP;

    public:
    ProjectileManager();
    void SetnbProjectile(int nb);
    int GetnbProjectile();
    void addProjectile(std::unique_ptr<Projectile> projectile);
    void removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove);
    void DamageTakenProjectile(bool b, bool isPlayer, Player* playerPtr, Invader* invaderPtr);
    bool isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile);
    bool hasProjectileCollided(const std::unique_ptr<Projectile>& projectile, Player* playerPtr, Invader* invaderPtr);
    void DrawProj(SDL_Renderer* renderer);
    void UpdateProj();
};


#endif
