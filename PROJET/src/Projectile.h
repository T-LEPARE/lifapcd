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
float dt;

std::map<std::string, weapon> weapons;

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
  












};

#endif 
