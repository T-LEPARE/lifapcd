#ifndef INVADERS_H
#define INVADERS_H

#include <SDL2/SDL.h>
#include "Position.h"
#include "Projectile.h"
#include "ProjectileManager.h"

class Invader {
private:
    Position pos;
    Position direction;
    float speed;
    float HP;
    int dmg;
    float width;
    float height;
    SDL_Surface* surface;
    SDL_Texture* texture;

public:
    /**
     @brief constructeur de Invader
    */
    Invader();

    /**
     * @brief Construct a new Invader object
     * 
     * @param x coordonné x
     * @param y coordonné y
     */
    Invader(float x,float y);

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

    

    void setDirection(float x,float y);
    void setDirection(Position p);

        /**
     * Donne une largeur au joueur
     * @param x  largeur en pixel
     */
    void setWidth(int w);
    
    /**
     * Donne une hauteur au joueur
     * @param x  hauteur en pixel
     */
    void setHeight(int h);


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
     * @return Retourne la largeur de l'Invader
     */
    float getWidth();

    /**
     * @return Retourne la hauteur du l'Invader
     */
    float getHeight();


    /**
     @brief les déplacements de l'Invader selon un pattern 
    */
    void movement();

   /**
    * @brief 
    * 
    * @return SDL_Texture* 
    */
    SDL_Texture* getTexture(); 

    /**
     * @brief 
     * 
     * @return SDL_Surface* 
     */
    SDL_Surface* getSurface();

    /**
     * @brief 
     * 
     * @param _texture 
     */
    void setTexture(SDL_Texture* _texture);

    /**
     * @brief 
     * 
     * @param _surface 
     */
    void setSurface(SDL_Surface* _surface);

    void shootInvader(ProjectileManager& tabpro);

    bool ArriveEnBas();

    bool HPnullInvader();
};




#endif