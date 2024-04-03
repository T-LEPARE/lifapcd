#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <map>
#include "WeaponManager.h"


class Player;
class ProjectileManager;

class Weapon {

public:

        Weapon();
        Weapon(std::string weaponName);


        ~Weapon();

        /**
         * @brief Get the weapons
         */
        /*void firePlayer(Player player,ProjectileManager tab);*/


        private:
        WeaponManager::weaponType weapon;
    



};

#endif 