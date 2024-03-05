#ifndef PROJECTILE_H
#define PROJECTILE_H


class Projectile {

private :
    float x;
    float y;
    float speed;
    int damage;

public :
    /**
     * @brief constructeur par defaut du projectiles 
    */
    Projectile();

    /**
     * @brief destructeur de projectile 
    */
    ~Projectile();

    /**
     * @brief permet au joueur de bouger sur l'écran
    */
    void move();

    /**
     * @return renvoie la position X du projectile
    */
   float getx();

   /**
     * @return renvoie la position y du projectile
    */
   float gety();

   /**
     * @return renvoie le degats de l'arme 
    */
   float getDamage();
  












};

#endif 
