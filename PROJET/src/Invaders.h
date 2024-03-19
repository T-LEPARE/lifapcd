#ifndef INVADERS_H
#define INVADERS_H
#include "Projectile.h"
#include "Position.h"
//#include "StarblitzGameDisplay.h"


class Invader {
private:
    Position pos;
    Position direction;
    float speed;
    float taille;
    float HP;
    int dmg;

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
     @param spd speed de l'invader
     @param damage damage de l'invader
    */
    Invader InitInvader(float x, float y, int HP,float spd,int damage);




    /**
     @brief Donne une position a l'invader
     @param x position x
     @param y position y
    */
    void setPos(float x,float y);
    void setPos(Position p);

    /**
     @brief Donne des Healthpoint a l'invader
     @param x HP
    */
    void setHP(int x);
    /**
     @brief Donne une vitesse a l'invader
     @param x speed
    */
    void setSpeed(float x);
    /**
     @brief Donne des damages a l'invader
     @param x damage
    */
    void setDamage(int x);

    /**
     * Donne une taille à l'Invader
     * @param TailleInvader  taille en pixel
     */
    void setTaille(float TailleInvader);

    void setDirection(float x,float y);
    void setDirection(Position p);



    /**
     @return retourne la position de l'Invader
    */
    Position getPos();

    /**
     * @return renvoie le degats de l'arme 
    */
    int getDamage();

    /**
     @return retourne le nombre de point de vie de l'invader
    */
    int getHP();

    /**
     * @return Retourne la speed de l'Invader
     */
    float getSpeed();

    /**
     * @return Retourne la taille de l'Invader
     */
    float getTaille();

    Position getDirection();


    /**
     @brief les déplacements de l'Invader selon un pattern 
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