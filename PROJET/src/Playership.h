#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "Projectile.h"
#include "Position.h"
#include "Invaders.h"
#include <SDL2/SDL.h>

class Player {
private:
    Position pos;
    float speed;
    float taille;
    int HP;

public:

    Player();

    /**
     * Constructeur de Player
     */
    Player(float x, float y, int healthPoint, float playerSpeed, float TaillePlayer);

    /**
     * Destructeur de Player
     */
    ~Player();

    /**
     * Initialise le joueur (vaisseau)
     * @param x Position x
     * @param y Position y
     * @param HP Vie du joueur
     * @return Le joueur initialisé
     */
    Player InitPlayer(float x, float y, int HP, float playerSpeed, float TaillePlayer);

    /**
     * Donne une position au joueur
     * @param x Position x
     * @param y Position y
     */
    void setPos(float x, float y);

    /**
     * Donne une position au joueur
     * @param x HealthPoint
     */
    void setHP(int x);

    /**
     * Donne une position au joueur
     * @param x  speed
     */
    void setSpeed(float x);

    /**
     * Donne une taille au joueur
     * @param x  taille en pixel
     */
    void setTaille(int t);
   
   
   
    /**
     * @return Retourne la position du joueur
     */
    Position getPos();

    /**
     * @return Retourne le nombre de points de vie du joueur
     */
    int getHP();

    /**
     * @return Retourne la speed du joueur
     */
    float getSpeed();

    /**
     * @return Retourne la taille du joueur
     */
    float getTaille();

    /**
     * Déplace le joueur
     */
    void movement();

    /**
     * Vérifie si le joueur a été touché par un projectile
     * @param P Un projectile
     * @return Vrai si collision, faux sinon
     */
    bool CheckCollisionP(Projectile P);

    /**
     * Si le joueur a été touché par un projectile, lui enlève de la vie
     * @param b Booléen indiquant la collision
     * @param P Un projectile
     */
    void DamageTakenP(bool b,Projectile P);

    /**
     * Vérifie si le joueur a été touché par un envahisseur
     * @param I Un envahisseur
     * @return Vrai si collision, faux sinon
     */
    bool CheckCollisionI(Invader I);

    /**
     * Si le joueur a été touché par un envahisseur, lui enlève de la vie
     * @param b Booléen indiquant la collision
     * @param I Un envahisseur
     */
    void DamageTakenI(bool b,Invader I);
};

#endif // PLAYERSHIP_H