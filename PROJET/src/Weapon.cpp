#include "Weapon.h"
#include "Projectile.h"




Weapon::Weapon() {

}

Weapon::~Weapon(){
    
}

std::map<std::string, WeaponManager::weaponType> WeaponManager::getWeapons() {
    return weaponTypes;
}


void Weapon::firePlayer(Player player, ProjectileManager tab) {
    // Create a new Projectile object
    std::unique_ptr<Projectile> p = std::make_unique<Projectile>(
        player.getPos(),                  // Position argument
        player.getCurrentWeaponName(),   // Current weapon name argument
        5.0f,                                // Width argument
        10.0f                                // Height argument
    );
    
    // Add the projectile to the projectile manager
    tab.addProjectile(std::move(p));
}