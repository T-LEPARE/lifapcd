#include "Projectile.h"



Projectile::Projectile(){
    projectileSpeed = 1; //vitesse du projectile
    damage = 1; //dégats d'un projectile de l'arme
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
    width = 5;
    height = 10;
}

Projectile::Projectile(float x,float y, std::string weaponName, WeaponManager& weaponManager) {
    this->pos.x = x; // Set position
    this->pos.y = y;
    this->damage = weaponManager.getDamage(weaponName); // Retrieve damage from weaponManager
    this->projectileSpeed = weaponManager.getProjectileSpeed(weaponName); // Retrieve projectile speed from weaponManager
    this->direction = Position(0, -1); // Set initial direction
    this->width = weaponManager.getProjectileWidth(weaponName); // Retrieve projectile width from weaponManager
    this->height = weaponManager.getProjectileHeight(weaponName); // Retrieve projectile height from weaponManager
    this->projectileRect = {int(pos.x),int(pos.y),int(width),int(height)};
}

Projectile::Projectile(const Position& pos){
    //celui des invaders
    WeaponManager weapon;
    this->pos = pos; // Set position
    this->damage = weapon.getDamage("mitraillette"); // Example with a specific weapon name
    this->projectileSpeed = weapon.getProjectileSpeed("mitraillette"); // Example with a specific weapon name
    this->direction = Position(0, 1); // Set initial direction
    this->width = weapon.getProjectileWidth("mitraillette");
    this->height = weapon.getProjectileHeight("mitraillette");
    this->projectileRect = {int(pos.x),int(pos.y),int(width),int(height)};
}





void Projectile::update() {
  // Use getters to access x and y from direction
  setPos(getPos() + getDir() * projectileSpeed * dt);
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
    return pos;
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
    return damage;
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
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer,&projectileRect);
}