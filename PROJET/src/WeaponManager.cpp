#include "WeaponManager.h"

WeaponManager::WeaponManager(){
    weaponTypes = {
            //nom, projectileSpeed, damage, fireRate, projectileWidth, projectileHeight
            {"mitraillette", {2, 1, 50, 1, 5}},
            {"railgun", {50, 50, 1, 5, 100}},
            {"roquettes", {20, 25, 2, 20,30}},
    };
}

WeaponManager::~WeaponManager(){}

int WeaponManager::getDamage(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).damage;
}


float WeaponManager::getProjectileSpeed(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileSpeed;
}

float WeaponManager::getProjectileWidth(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileWidth;
}

float WeaponManager::getProjectileHeight(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileHeight;
}

std::map<std::string, WeaponManager::weaponType> WeaponManager::getWeapons() {
    return weaponTypes;
}