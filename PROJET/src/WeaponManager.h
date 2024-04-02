#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <map>
#include <string>
#include <memory>
#include <vector>


class WeaponManager {
public:

    struct weaponType {
                float projectileSpeed;
                int damage;
                float fireRate;
            };
    std::map<std::string, weaponType> getWeapons();

    int getDamage(const std::string& weaponName) const;
        

    float getProjectileSpeed(const std::string& weaponName) const;


private:
    std::map<std::string, weaponType> weaponTypes = {
            //nom, projectileSpeed, damage, fireRate
            {"mitraillette", {2, 1, 50}},
            {"railgun", {50, 50, 1}},
            {"roquettes", {20, 25, 2}},
    };
};

#endif
