#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include <vector>
#include "Position.h"
#include "Weapon.h"


//Le delta temps pour modifier la vitesse des projectiles
const float dt = 0.1;



class Projectile {

private :
        Position pos;
        Position direction;
        int damage;
        float projectileSpeed;

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
        Projectile(const Position& pos, const Weapon& weapon, std::string weaponName);

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
    
};

#endif 
