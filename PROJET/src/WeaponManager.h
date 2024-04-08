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

    float getfireRate(const std::string& weaponName) const;

    float getProjectileWidth(const std::string& weaponName) const;

    float getProjectileHeight(const std::string& weaponName) const;


private:
    std::map<std::string, weaponType> weaponTypes;
};

#endif
