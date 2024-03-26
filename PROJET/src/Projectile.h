#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include <vector>
#include "Position.h"

static std::map<std::string, weapon> weaponTypes = {
    // {nom,{projectile speed projectile,damage, fire rate}}
    {"mitraillette",{2, 1, 50}},
    {"railgun", {50, 50, 1}},
    {"roquettes", {20, 25, 2}},
};

struct weapon {
    float projectileSpeed;
    int damage;
    float fireRate;
    static std::map<std::string, weapon> weaponTypes;
};



//Le delta temps pour modifier la vitesse des projectiles
const float dt = 0.1;



class Projectile : public weapon {

private :
    Position pos;
    Position direction;
    float projectileSpeed; 
    int damage;
    float fireRate;
    static weapon weapons;
    
    
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
        Projectile(Position pos, const weapon& wpn, std::string weaponName);

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
        int getDamage();
       
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
         * @brief Set the fireRate object
         */
        void setFireRate();

        /**
         * @brief Get the fireRate object
         */
        float getFireRate();

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

        static weapon getWeapons();

};

#endif 
