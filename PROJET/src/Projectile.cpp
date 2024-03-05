#include "Projectile.h"

std::map<std::string, weapon> weapons {
    // {nom,{vitesse,damage}}
    {"mitraillette",{1, 1}},
    {"railgun", {10,100}},
};





Projectile::Projectile(){
    speed = 1;
    damage = 1;
    pos = Position();  
}

Projectile::Projectile(Position pos,std::map<std::string, weapon> weapons,std::string weaponName){
    this->pos = pos; // Ici il faudra faire un getPos() soit pour l'invader soit pour le Playership
    this->damage = weapons[weaponName].damage;
    this->speed = weapons[weaponName].speed;
}