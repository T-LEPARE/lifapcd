#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Position.h"
#include <map>
#include <string>
#include <vector>

struct weapon {
    float speed;
    float damage;
};

//Le delta temps pour modifier la vitesse des projectiles
const float dt = 0.1;

std::map<std::string, weapon> weapons {
    // {nom,{vitesse,damage}}
    {"mitraillette",{100, 1}},
    {"railgun", {1,100}},
};

class Projectile {

private :
    Position pos;
    Position direction;
    float speed;
    int damage;
    
    

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
        Projectile(Position pos,std::map<std::string, weapon> weapons, std::string weaponName);

        /**
         * @brief destructeur de projectile 
        */
        ~Projectile();


        /**
         * @brief met à jour le projectile (position) 
        */
         void update();

        /**
        * @return renvoie le degats de l'arme 
        */
        float getDamage();
       
        /**
         * @brief Get the Pos object
         * 
         * @return Position 
         */
        Position getPos();

        /**
         * @brief Set the Pos object
         * 
         * @param x 
         * @param y 
         */
        void setPos(float x,float y);

        /**
         * @brief Set the Pos object
         * 
         * @param p 
         */
        void setPos(Position p);

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
  












};

#endif 
