#include "Weapon.h"
#include "Projectile.h"




Weapon::Weapon() {

}

Weapon::~Weapon(){
    
}

//Problème ici, ça ira pas, compliqué de lui passer un player ?
void Weapon::firePlayer(Player player, ProjectileManager tab) {
    // Create a new Projectile object
    std::unique_ptr<Projectile> p = std::make_unique<Projectile>(
        player.getPos(),                  
        player.getCurrentWeaponName()                    
    );
    
    // Add the projectile to the projectile manager
    tab.addProjectile(std::move(p));
}