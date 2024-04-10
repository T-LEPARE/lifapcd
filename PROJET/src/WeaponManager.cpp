#include "WeaponManager.h"
#include <iostream>

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

std::string WeaponManager::getnextWeaponName(const std::string& weaponName) {

    auto it = weaponTypes.find(weaponName);
    
    if (it != weaponTypes.end()) {

        ++it;

        if (it != weaponTypes.end()) {
            return it->first;
        } else {

            return weaponTypes.begin()->first;
        }
    } else {
        std::cout << "Erreur dans la récupération du nom de la prochaine arme" << std::endl;
        exit(EXIT_FAILURE);
    }
}
