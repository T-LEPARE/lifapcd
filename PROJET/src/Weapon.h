#ifndef WEAPON_H
#define WEAPON_H

class Player;

#include <map>
#include <string>
#include <memory>
#include <vector>
#include "Position.h"
#include "Invaders.h"
#include "ProjectileManager.h"
#include "WeaponManager.h"

class ProjectileManager;
class Weapon {

public:

        Weapon();
        Weapon(std::string weaponName);


        ~Weapon();

        /**
         * @brief Get the weapons
         */
        void firePlayer(Player player,ProjectileManager tab);


        private:
        WeaponManager::weaponType weapon;
    



};

#endif 