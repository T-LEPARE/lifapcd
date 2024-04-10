#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

class ProjectileManager;

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "Position.h"
#include "Projectile.h"
#include "Weapon.h"
#include "WeaponManager.h"
#include "Invaders.h"


class Invader;

class Player {
private:
    int HP;
    float speed;
    int height;
    int width;
    Position pos;
    Position direction;
    Weapon currentWeapon;
    std::string currentWeaponName;
    SDL_Texture* texture;
    SDL_Surface* surface;
    Uint32 dernier_tir;


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

    bool CheckCollisionProjectile(Projectile Projectile);
    void DamageTakenProjectile(bool b, Projectile Projectile);
    bool CheckCollisionInvader(Invader Invader);
    void DamageTakenInvader(bool b, Invader Invader);
    void setCurrentWeapon(Weapon weapon);
    void changeWeapon(WeaponManager& weaponManager);
    void CollisionWindow();
    std::string getCurrentWeaponName();
    Weapon getCurrentWeapon();
    bool peutTirer();
    void firePlayer(ProjectileManager& projectileManager, WeaponManager& weaponManager,const Uint8 *keyboardState);
    bool HPnullPlayership();
    void moveShip(const Uint8 *keyboardState);
    void playerDeath(ProjectileManager& projectileManager);
};

#endif