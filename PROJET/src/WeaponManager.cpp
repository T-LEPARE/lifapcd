#include "WeaponManager.h"

WeaponManager::WeaponManager(){}

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