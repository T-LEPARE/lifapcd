#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include <SDL2/SDL.h>
#include "Position.h"
#include "WeaponManager.h"


//Le delta temps pour modifier la vitesse des projectiles
const float dt = 0.1;


class Projectile {

private :
        Position pos;
        Position direction;
        int damage;
        float projectileSpeed;
        SDL_Rect projectileRect;
        float height;
        float width;
        bool ProvenanceDuTir;

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
        Projectile(float x,float y, std::string weaponName, WeaponManager& weaponManager);


        /**
        * @brief Constructor for Projectile based on invader position and damage.
        * 
        * @param invPos Position of the Invader that fired the Projectile.
        * @param dmg Damage inflicted by the Projectile.
        */
        Projectile(const Position& invPos, const int& dmg);

        /**
         * @brief destructeur de projectile 
        */
        ~Projectile();


        /**
         * @brief met à jour le projectile (position)
        */
         void update();

        /**
         * @brief Get who is shooting
         * 
         * @return a bool that design who is shooting 
         */
        bool getProvenaceDuTir();
       
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
         * @brief Draws the Player's Projectile on the specified renderer.
         * @param renderer Reference to an SDL_Renderer object.
        */
        void drawProjectilePlayer(SDL_Renderer* renderer);

        /**
         * @brief Draws the Invader's Projectile on the specified renderer.
         * @param renderer Reference to an SDL_Renderer object.
        */
        void drawProjectileInvader(SDL_Renderer* renderer);
};

#endif 
