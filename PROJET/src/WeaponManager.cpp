#include "WeaponManager.h"

WeaponManager::WeaponManager(){
    weaponTypes = {
            //nom, projectileSpeed, damage, fireRate, projectileWidth, projectileHeight
            {"mitraillette", {7, 1, 100, 1, 5}},
            {"railgun", {5, 50, 1, 5, 100}},
            {"roquettes", {3, 25, 2, 20,30}},
    };
}

WeaponManager::~WeaponManager(){}

int WeaponManager::getDamage(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).damage;
}


float WeaponManager::getProjectileSpeed(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileSpeed;
}

float WeaponManager::getfireRate(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).fireRate;
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