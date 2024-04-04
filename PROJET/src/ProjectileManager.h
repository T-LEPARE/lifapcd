#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Playership.h"
#include "Invaders.h"
#include "StarblitzGameDisplay.h"



class Player;
class Invader;
class ProjectileManager {
    private:
    std::vector<std::unique_ptr<Projectile>> projectiles;

    public:
    ProjectileManager();
    void SetnbProjectile(int nb);
    int GetnbProjectile();
    void addProjectile(std::unique_ptr<Projectile> projectile);
    void removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove);
    void DamageTakenProjectile(Player* playerPtr, Invader* invaderPtr);
    bool isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile) const;
    void hasProjectileCollided( Player* playerPtr, std::vector<Invader>* invaders);
    void DrawProj(SDL_Renderer* renderer);
    void UpdateProj();
};


#endif
