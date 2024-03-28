#include "Weapon.h"
#include "Projectile.h"



Weapon::Weapon() {

}

Weapon::~Weapon(){
    
}

std::map<std::string, Weapon::weaponType> Weapon::getWeapons() {
    return weaponTypes;
}

// A voir
void Weapon::weaponType::fire(std::vector<std::unique_ptr<Projectile>>& projectiles, const Position& pos, const Position& direction) {
        
}


int Weapon::getDamage(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).damage;
}


float Weapon::getProjectileSpeed(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileSpeed;
}