#ifndef INVADERS_H
#define INVADERS_H
#include <Projectile.h>
#include <Position.h>

class Invader {
private:
    Position pos;
    float speed;

public:
    /**
     @brief constructeur de Invader
    */
    Invader();

    /**
     @brief destructeur de Invader
    */
    ~Invader();

    /**
     @brief initialisation de l'Invader
     @param x  position x 
     @param y  position y
     @param HP vie de l'Invader 
    */
    Invader InitInvader(float x, float y, int HP);

    /**
     @return retourne la position de l'Invader
    */
    Position getPos();

    /**
     @return retourne le nombre de point de vie de l'invader
    */
    int getHP();

    /**
     @brief les déplacements de l'Invader selon un pattern
     @param le point d'arrivé de l'invader 
    */
    void movement();

    /**
     @brief Vérifie si l'invader a été touché par un projectile
     @param  P Un projectile 
    */
    bool CheckCollision(Projectile P);

     /**
     @brief Si l'invader a été touché par un projectile alors on lui enlève de la vie
     @param  b le booléen exprimant la collision
     @param  P Un projectile 
    */
    void DamageTaken(bool b, Projectile P);
};


#endif
