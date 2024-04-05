#include "Projectile.h"
#include <iostream>



Projectile::Projectile(){
    projectileSpeed = 1; //vitesse du projectile
    damage = 1; //dégats d'un projectile de l'arme
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(0,0); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
    width = 5;
    height = 10;
}

Projectile::Projectile(float x,float y, std::string weaponName, WeaponManager& weaponManager) {
    pos = Position(x,y);
    damage = weaponManager.getDamage(weaponName); // Retrieve damage from weaponManager
    projectileSpeed = weaponManager.getProjectileSpeed(weaponName); // Retrieve projectile speed from weaponManager
    direction = Position(0, -1); // Set initial direction
    width = weaponManager.getProjectileWidth(weaponName); // Retrieve projectile width from weaponManager
    height = weaponManager.getProjectileHeight(weaponName); // Retrieve projectile height from weaponManager
    projectileRect = {int(pos.x),int(pos.y),int(width),int(height)};
}

Projectile::Projectile(const Position& posi, WeaponManager& weaponManager){
    //celui des invaders
    pos = posi; // Set position
    damage = weaponManager.getDamage("mitraillette"); // Example with a specific weapon name
    projectileSpeed = weaponManager.getProjectileSpeed("mitraillette"); // Example with a specific weapon name
    direction = Position(0, -1); // Set initial direction
    width = weaponManager.getProjectileWidth("mitraillette");
    height = weaponManager.getProjectileHeight("mitraillette");
    projectileRect = {int(pos.x),int(pos.y),int(width),int(height)};
}





void Projectile::update() {
  // Use getters to access x and y from direction
  setPos(getPos() + getDir() * projectileSpeed);
  this->projectileRect = {int(this->getPos().x),int(this->getPos().y),int(this->getWidth()),int(this->getHeight())};
}


Projectile::~Projectile(){

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
    return direction;
}

void Projectile::setDir(float x,float y){
    this->direction.x=x;
    this->direction.y=y;
}

void Projectile::setDir(Position p){
    this->pos.x=p.x;
    this->pos.y=p.y;
}

int Projectile::getDamage() {
    return this->damage;
}

  float Projectile::getWidth()
    {
        return this->width;
    }

    float Projectile::getHeight()
    {
        return this->height;
    }

void Projectile::setProjectileRect(int x ,int y,int width,int height){
    this->projectileRect = {int(x),int(y),int(width),int(height)};
}

void Projectile::drawProjectile(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer,&projectileRect);
}