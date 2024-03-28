#include "Projectile.h"



Projectile::Projectile(){
    projectileSpeed = 1; //vitesse du projectile
    damage = 1; //dégats d'un projectile de l'arme
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
}

Projectile::Projectile(const Position& pos, const Weapon& weapon, std::string weaponName) {
    this->pos = pos; // Set position
    this->damage = weapon.getDamage(weaponName); // Example with a specific weapon name
    this->projectileSpeed = weapon.getProjectileSpeed(weaponName); // Example with a specific weapon name
    this->direction = Position(0, -1); // Set initial direction
}


void Projectile::update() {
  // Use getters to access x and y from direction
  setPos(getPos() + getDir() * projectileSpeed * dt);
}


Projectile::~Projectile(){
    //a voir

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

int Projectile::getDamage() {
    return damage;
}
