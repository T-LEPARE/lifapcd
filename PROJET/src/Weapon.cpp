#include "Weapon.h"



Weapon::Weapon() {}
Weapon::Weapon(std::string weaponName) {
    WeaponManager weaponManager;
    std::map<std::string, WeaponManager::weaponType> weaponList = weaponManager.getWeapons();
    weapon = weaponList.at(weaponName);

}

Weapon::~Weapon(){
    
}

