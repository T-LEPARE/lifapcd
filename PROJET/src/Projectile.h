#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include <vector>
#include "Position.h"
#include <SDL2/SDL.h>


//Le delta temps pour modifier la vitesse des projectiles
const float dt = 0.1;

class Weapon;

class Projectile {

private :
        Position pos;
        Position direction;
        int damage;
        float projectileSpeed;
        SDL_Rect projectileRect;
        float height;
        float width;

public :


        /**
         * @brief constructeur par defaut du projectiles 
        */
        Projectile();

        /**
         * @brief Construct a new Projectile object
         * 
         * @param pos 
         * @param weapons 
         * @param weaponName 
         */
        Projectile(const Position& pos, const Weapon& weapon, std::string weaponName,float width,float height);

        /**
         * @brief destructeur de projectile 
        */
        ~Projectile();


        /**
         * @brief met à jour le projectile (position)
        */
         void update();


       
        /**
         * @brief Get the Pos object
         * 
         * @return Position 
         */
        Position getPos();

        /**
         * @brief Set the Pos object
         * 
         * @param p 
         */
        void setPos(Position p);

                /**
         * @brief Set the Pos object
         * 
         * @param x
         * @param y 
         */
        void setPos(float x, float y);



        /**
         * @brief Get the Dir object
         * 
         * @return Position 
         */

        Position getDir();

        /**
         * @brief Set the Dir object
         * 
         * @param x 
         * @param y 
         */
        void setDir(float x,float y);

        /**
         * @brief Set the Dir object
         * 
         * @param p 
         */
        void setDir(Position p);

        int getDamage();
    
        
        /**
         * @return Retourne la largeur de l'Invader
         */
        float getWidth();

        /**
         * @return Retourne la hauteur du l'Invader
         */
        float getHeight();
       
        /**
         * @brief Set the Projectile Rect object
         * 
         * @param x 
         * @param y 
         * @param width 
         * @param height 
         */
        void setProjectileRect(int x ,int y,int width,int height);
       
        /**
         * @brief 
         * 
         * @param renderer 
         */
        void drawProjectile(SDL_Renderer* renderer);
};

#endif 
