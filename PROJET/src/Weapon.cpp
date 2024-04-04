#include "Weapon.h"
#include <iostream>


Weapon::Weapon() {}
Weapon::Weapon(std::string weaponName) {
  WeaponManager weaponManager;
  std::map<std::string, WeaponManager::weaponType> weaponList = weaponManager.getWeapons();
  std::cout << "Damage : " << weaponList.at(weaponName).damage << std::endl;
  weapon = weaponList.at(weaponName);
  
}

Weapon::~Weapon(){
    
}

