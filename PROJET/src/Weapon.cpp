#include "Weapon.h"
#include "Playership.h"
#include "Projectile.h"




Weapon::Weapon(std::string weaponName) {
    WeaponManager weaponManager;
    std::map<std::string, WeaponManager::weaponType> weaponList = weaponManager.getWeapons();
    try {
        weapon = weaponList.at(weaponName);
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Weapon not found: " + weaponName);
    }
}

Weapon::~Weapon(){
    
}

