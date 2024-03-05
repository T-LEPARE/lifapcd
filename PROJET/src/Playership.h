#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <Position.h>

class Player {
private:
    Position pos;
    float speed;

public:
    /**
     @brief constructeur de Player
    */
    Player();

    /**
     @brief destructeur de Player
    */
    ~Player();

    /**
     @brief initialisation du joueur (vaisseau)
     @param x  position x 
     @param y  position y
     @param HP vie du joueur 
    */
    Player InitPlayer(float x, float y, int HP);

    /**
     @return retourne la position du joueur
    */
    Position getPos();

    /**
     @return retourne le nombre de point de vie du joueur
    */
    int getHP();

    /**
     @brief les déplacements du joueur 
    */
    void movement();

    /**
     @brief Vérifie si le joueur a été touché ou non
     @param  P position d'un invader ou d'un projectile
    */
    bool CheckCollision(Position P);
};



#endif