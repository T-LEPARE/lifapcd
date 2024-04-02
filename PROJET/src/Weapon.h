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


class Projectile;

class Weapon {

public:
        struct weaponType {
                float projectileSpeed;
                int damage;
                float fireRate;
                
            };

        Weapon();


        ~Weapon();

        /**
         * @brief Get the weapons
         */
        std::map<std::string, weaponType> getWeapons();

        int getDamage(const std::string& weaponName) const;
        

        float getProjectileSpeed(const std::string& weaponName) const;

        void fireplayer(Player p1, const Position& direction,Weapon w,ProjectileManager tab1);



        private:
    
    std::map<std::string, weaponType> weaponTypes = {
            {"mitraillette", {2, 1, 50}},
            {"railgun", {50, 50, 1}},
            {"roquettes", {20, 25, 2}},
        };


};

#endif 