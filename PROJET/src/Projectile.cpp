#include "Projectile.h"

std::vector<Projectile> weapon {
    {speed=}
};


Projectile::Projectile(){
    speed = 1;
    damage = 1;
    pos = Position();  
}

Projectile::Projectile(Position pos,std::vector<Projectile> weapon,int indice){
    this->pos = pos;
    this->damage = weapon[indice].damage;
    this->speed = weapon[indice].speed;
}