#ifndef INVADERS_H
#define INVADERS_H

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
    void movement(Position pointFinal);

    /**
     @brief Vérifie si l'invader a été touché par un projectile
     @param  P position d'un projectile
    */
    bool CheckCollision(Position P);
};



#endif