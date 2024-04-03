#ifndef INVADERS_MANAGER_H
#define INVADERS_MANAGER_H
#include "Position.h"
#include "Projectile.h"
#include "Playership.h"
#include "Invaders.h"
#include "StarblitzGameDisplay.h"
#include <vector>
#include <memory>
#include <algorithm>
#include "Weapon.h"


class Player;
class ProjectileManager {
    private:
    std::vector<std::unique_ptr<Projectile>> projectiles;
    public:
    void addProjectile(std::unique_ptr<Projectile> projectile);
    void removeProjectile(const std::unique_ptr<Projectile>& projectileToRemove);
    void DamageTakenProjectile(bool b, bool isPlayer, Player* playerPtr, Invader* invaderPtr);
    bool isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile);
    bool hasProjectileCollided(const std::unique_ptr<Projectile>& projectile, Player* playerPtr, Invader* invaderPtr);
};


#endif