#include "Weapon.h"
#include "Projectile.h"




Weapon::Weapon() {

}

Weapon::~Weapon(){
    
}

std::map<std::string, Weapon::weaponType> Weapon::getWeapons() {
    return weaponTypes;
}


void Weapon::fireplayer(Player player,const Position& direction,Weapon w,ProjectileManager tab) {
        std::unique_ptr<Projectile> p = std::make_unique<Projectile>((player.getPos(),w,player.getCurrentWeaponName(),5,10));
        tab.addProjectile(std::move(p));
}
        



int Weapon::getDamage(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).damage;
}


float Weapon::getProjectileSpeed(const std::string& weaponName) const {
    return weaponTypes.at(weaponName).projectileSpeed;
}