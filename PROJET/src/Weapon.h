#ifndef WEAPON_H
#define WEAPON_H
#include <map>
#include <string>
#include <memory>
#include <vector>
#include "Position.h"
#include "Playership.h"
#include "Invaders.h"
#include"ProjectileManager.h"
#include "WeaponManager.h"

class Projectile;
class Player;
class ProjectileManager;

class Weapon {

public:

        Weapon();


        ~Weapon();

        /**
         * @brief Get the weapons
         */
        void firePlayer(Player player, ProjectileManager tab);

        //WeaponManager::weaponType weaponType;


        private:
    



};

#endif 