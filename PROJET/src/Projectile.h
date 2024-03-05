#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Position.h"


class Projectile {

private :
    Position pos;
    float speed;
    int damage;

public :
    /**
     * @brief constructeur par defaut du projectiles 
    */
    Projectile();

    /**
     * @brief destructeur de projectile 
    */
    ~Projectile();

    /**
     * @brief permet au joueur de bouger sur l'écran
    */
    void move();

    /**
     * @return renvoie la position du projectile 
    */
   float getpos();

   

   /**
     * @return renvoie le degats de l'arme 
    */
   float getDamage();
  












};

#endif 
