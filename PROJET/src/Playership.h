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
    /**
     * Constructeur de Player
     */
    Player();

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
    Player InitPlayer(float x, float y, int HP);

    /**
     * Donne une position au joueur
     * @param x Position x
     * @param y Position y
     */
    void setPos(float x, float y);

    /**
     * @return Retourne la position du joueur
     */
    Position getPos() const;

    /**
     * @return Retourne le nombre de points de vie du joueur
     */
    int getHP() const;

    /**
     * Déplace le joueur
     */
    void movement();

    /**
     * Vérifie si le joueur a été touché par un projectile
     * @param P Un projectile
     * @return Vrai si collision, faux sinon
     */
    bool CheckCollision(const Projectile& P) const;

    /**
     * Si le joueur a été touché par un projectile, lui enlève de la vie
     * @param b Booléen indiquant la collision
     * @param P Un projectile
     */
    void DamageTaken(bool b, const Projectile& P);

    /**
     * Vérifie si le joueur a été touché par un envahisseur
     * @param I Un envahisseur
     * @return Vrai si collision, faux sinon
     */
    bool CheckCollision(const Invader& I) const;

    /**
     * Si le joueur a été touché par un envahisseur, lui enlève de la vie
     * @param b Booléen indiquant la collision
     * @param I Un envahisseur
     */
    void DamageTaken(bool b, const Invader& I);
};

#endif // PLAYERSHIP_H