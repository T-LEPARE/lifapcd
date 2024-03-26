#ifndef WEAPON_H
#define WEAPON_H
#include <map>
#include <string>
#include <memory>
#include "Projectile.h"

class Weapon {

private:
    struct weaponType {
        float projectileSpeed;
        int damage;
        float fireRate;
    };
    
    std::map<std::string, weaponType> weaponTypes = {
            {"mitraillette", {2, 1, 50}},
            {"railgun", {50, 50, 1}},
            {"roquettes", {20, 25, 2}},
        };


public:

        Weapon();

        ~Weapon();

        /**
         * @brief Get the weapons
         */
        std::map<std::string, weaponType> getWeapons();

        int getDamage(const std::string& weaponName) const {
            return weaponTypes.at(weaponName).damage;
        }

        float getProjectileSpeed(const std::string& weaponName) const {
            return weaponTypes.at(weaponName).projectileSpeed;
        }

        /**
        * @return renvoie le degats de l'arme 
        */

        //void fire(std::vector<std::unique_ptr<Projectile>>& projectiles, const Position& pos, const Position& direction);
};

#endif 