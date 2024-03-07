#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <Projectile.h>
#include <Position.h>
#include <Invaders.h>

class Player {
    private:
        Position pos;
        float speed;
        float taille;
        float HP;
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
        @brief Donne une position a l'invader
        @param x position x
        @param y position y
        */
        void setPos(float x,float y);

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
        @param  P Un projectile
        */
        bool CheckCollision(Projectile P);

        /**
         @brief Si le joueur a été touché par un projectile alors on lui enlève de la vie
        @param  b le booléen exprimant la collision
        @param  P Un projectile 
        */
        void DamageTaken(bool b, Projectile P);

        /**
         @brief Vérifie si le joueur a été touché ou non
        @param  P Un Invader
        */
        bool CheckCollision(Invader P);

        /**
         @brief Si le joueur a été touché par un Invader alors on lui enlève de la vie
        @param  b le booléen exprimant la collision
        @param  P Un Invader 
        */
        void DamageTaken(bool b, Invader P);
};


#endif
