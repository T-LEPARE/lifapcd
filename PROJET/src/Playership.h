#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <iostream>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "Position.h"
#include "Projectile.h"
#include "ProjectileManager.h"
#include "Weapon.h"
#include "Invaders.h"

class Weapon;

class Player {
private:
    int HP;
    float speed;
    float height;
    float width;
    Position pos;
    Position direction;
    Weapon::weaponType currentWeapon;
    std::string currentWeaponName;
    SDL_Texture* texture;
    SDL_Surface* surface;

public:
    Player();
    Player(float x, float y, int healthPoint, float playerSpeed, float height, float width, Position direct);
    ~Player();

    Player InitPlayer(float x, float y, int healthPoint, float spd, float height, float width, Position direct);

    void setPos(float x, float y);
    void setHP(int healthPoint);
    void setSpeed(float speed);
    void setWidth(int w);
    void setHeight(int h);
    void setDirX(float x);
    void setDirY(float y);
    void setDir(Position p);

    SDL_Texture* getTexture();
    SDL_Surface* getSurface();
    void setTexture(SDL_Texture* _texture);
    void setSurface(SDL_Surface* _surface);

    Position getDir();
    int getHP();
    float getSpeed();
    Position getPos();
    float getWidth();
    float getHeight();

    void movement(SDL_Event& event);
    bool CheckCollisionProjectile(Projectile Projectile);
    void DamageTakenProjectile(bool b, Projectile Projectile);
    bool CheckCollisionInvader(Invader Invader);
    void DamageTakenInvader(bool b, Invader Invader);
    void addProjectile(std::unique_ptr<Projectile> projectile);
    void shoot();
    void setCurrentWeapon(Weapon::weaponType weapon);
    void changeWeapon(const std::string& weaponName); // Changed to take the name of the weapon
    bool CollisionWindow();
    std::string getCurrentWeaponName();
};

#endif // PLAYER_H
