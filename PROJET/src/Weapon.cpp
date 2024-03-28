#include "Weapon.h"


Weapon::Weapon() {
}

Weapon::~Weapon(){

}

std::map<std::string, Weapon::weaponType> Weapon::getWeapons() {
    return weaponTypes;
}


void Weapon::fire(std::vector<std::unique_ptr<Projectile>>& projectiles, const Position& pos, const Position& direction) {
    
}