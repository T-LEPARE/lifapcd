#include "Projectile.h"
#include <iostream>



Projectile::Projectile(){
    //default projectile constructor
    projectileSpeed = 1; //vitesse du projectile
    damage = 1; //dégats d'un projectile de l'arme
    direction = Position(0,-1); // la direction initiale du tir, vers le bas
    pos = Position(0,0); // ici on verra comment on fait, il faut récupérer la position de l'entité qui crée le projectile
    width = 5;
    height = 10;
}

Projectile::Projectile(float x,float y, std::string weaponName, WeaponManager& weaponManager) {
    //player projectile constructor
    pos = Position(x,y);
    damage = weaponManager.getDamage(weaponName); // Retrieve damage from weaponManager
    projectileSpeed = weaponManager.getProjectileSpeed(weaponName); // Retrieve projectile speed from weaponManager
    direction = Position(0, -1); // Set initial direction
    width = weaponManager.getProjectileWidth(weaponName); // Retrieve projectile width from weaponManager
    height = weaponManager.getProjectileHeight(weaponName); // Retrieve projectile height from weaponManager
    projectileRect = {int(pos.x),int(pos.y),int(width),int(height)};
}

Projectile::Projectile(const Position& invPos, const int& dmg) {
    //invader projectile constructor
    pos = invPos;
    direction = Position(0,1); // les invaders tirent vers le bas
    damage = dmg;
    projectileSpeed = 1; //Les invaders auront tous la meme projectile speed ? Sinon il faut rajouter la projectileSpeed dans invaders
    width = 1; //Les invaders auront tous la meme projectile width ? Sinon il faut rajouter la projectileWidth dans invaders
    height = 5; //Les invaders auront tous la meme projectile height ? Sinon il faut rajouter la projectileHeight dans invaders
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