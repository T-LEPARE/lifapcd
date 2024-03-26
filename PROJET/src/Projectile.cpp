#include "Projectile.h"



Projectile::Projectile(){
    projectileSpeed = 1; //vitesse du projectile
    damage = 1; //dégats d'un projectile de l'arme
    fireRate = 1;  //vitesse de tir
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
}

Projectile::Projectile(Position pos,std::map<std::string, weapon> weapons,std::string weaponName){
    this->pos = pos; // Ici il faudrait faire un getPos() soit pour l'invader soit pour le Playership, mais comme la position sera l'angle supérieur gauche, il faudra modifier pour que ça parte de la moitié du mec...
    this->damage = weapons[weaponName].damage;
    this->projectileSpeed = weapons[weaponName].projectileSpeed;
    this->direction = Position(0,-1); // la direction initiale du tir
}


void Projectile::update() {
  // Use getters to access x and y from direction
  setPos(getPos() + getDir() * projectileSpeed * dt);
}

int Projectile::getDamage(){
    return damage;
}

Projectile::~Projectile(){
    this->damage = 0;

}

Position Projectile::getPos(){
    return pos;
}

void Projectile::setPos(float x,float y){
    this->pos.x=x;
    this->pos.y=y;
}

void Projectile::setPos(Position p){
    this->pos.x=p.x;
    this->pos.y=p.y;
}

Position Projectile::getDir(){
    return pos;
}

void Projectile::setDir(float x,float y){
    this->pos.x=x;
    this->pos.y=y;
}

void Projectile::setDir(Position p){
    this->pos.x=p.x;
    this->pos.y=p.y;
}

weapon Projectile::getWeapons() {
    return weapons;
}