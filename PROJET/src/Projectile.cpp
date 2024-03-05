#include "Position.h"
#include "Projectile.h"

float dt = 0.1;

std::map<std::string, weapon> weapons {
    // {nom,{vitesse,damage}}
    {"mitraillette",{1, 1}},
    {"railgun", {10,100}},
};

Projectile::Projectile(){
    // celui-là je suis pas sûr qu'il ai un intérêt, on utilisera jamais le constructeur par défaut d'un projectile comme ça
    speed = 1;
    damage = 1;
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
}

Projectile::Projectile(Position pos,std::map<std::string, weapon> weapons,std::string weaponName){
    this->pos = pos; // Ici il faudrait faire un getPos() soit pour l'invader soit pour le Playership, mais comme la position sera l'angle supérieur gauche, il faudra modifier pour que ça parte de la moitié du mec...
    this->damage = weapons[weaponName].damage;
    this->speed = weapons[weaponName].speed;
    this->direction = Position(0,-1); // la direction initiale du tir, vers le bas
}

void Projectile::update() {
  // Use getters to access x and y from direction
  this->pos.setX(this->pos.getX() + direction.getX() * this->speed * dt);
  this->pos.setY(this->pos.getY() + direction.getY() * this->speed * dt);
}