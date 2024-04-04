#include "Weapon.h"
#include <iostream>


Weapon::Weapon() {}

Weapon::Weapon(std::string weaponName, WeaponManager& weaponManager) {
    std::map<std::string, WeaponManager::weaponType> weaponList = weaponManager.getWeapons();
    std::cout << "WeaponList size: " << weaponList.size() << std::endl;
    if (weaponList.count(weaponName)) {
        std::cout << "Damage : " << weaponList.at(weaponName).damage << std::endl;
        weapon = weaponList.at(weaponName);
    } else {
        std::cout << "Weapon '" << weaponName << "' not found in WeaponList!" << std::endl;
    }
}
Weapon::~Weapon(){
    
}

