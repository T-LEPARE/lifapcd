#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <map>
#include <string>

class WeaponManager {
public:

    WeaponManager();
    ~WeaponManager();
    struct weaponType {
                float projectileSpeed;
                int damage;
                float fireRate;
                int projectileWidth;
                int projectileHeight;
            };
    std::map<std::string, weaponType> getWeapons();

    int getDamage(const std::string& weaponName) const;
        

    float getProjectileSpeed(const std::string& weaponName) const;

    float getProjectileWidth(const std::string& weaponName) const;

    float getProjectileHeight(const std::string& weaponName) const;


private:
    std::map<std::string, weaponType> weaponTypes = {
            //nom, projectileSpeed, damage, fireRate, projectileWidth, projectileHeight
            {"mitraillette", {2, 1, 50, 5, 1}},
            {"railgun", {50, 50, 1, 5, 100}},
            {"roquettes", {20, 25, 2, 20,30}},
    };
};

#endif
