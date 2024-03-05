#include "Projectile.h"

std::map<std::string, weapon> weapons {
    // {nom,{vitesse,damage}}
    {"mitraillette",{1, 1}},
    {"railgun", {10,100}},
};





Projectile::Projectile(){
    // celui-là je suis pas sûr qu'il ai un intérêt, on utilisera jamais le constructeur par défaut d'un projectile comme ça
    speed = 1;
    damage = 1;
    pos = Position();  
}

Projectile::Projectile(Position pos,std::map<std::string, weapon> weapons,std::string weaponName){
    this->pos = pos; // Ici il faudrait faire un getPos() soit pour l'invader soit pour le Playership, mais comme la position sera l'angle supérieur gauche, il faudra modifier pour que ça parte de la moitié du mec...
    this->damage = weapons[weaponName].damage;
    this->speed = weapons[weaponName].speed;
}