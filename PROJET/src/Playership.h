#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

class ProjectileManager;  // Forward declaration

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Position.h"
#include "Projectile.h"
#include "Weapon.h"
#include "WeaponManager.h"
#include "Invaders.h"

class Invader;  // Forward declaration

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
  Uint32 dernier_tir;  // Time of last shot 
  Uint32 dernier_changement;  // Time of last weapon change

public:
  /**
   * @brief Default constructor for Player. Initializes with default values.
   */
  Player();

  /**
   * @brief Constructor for Player.
   * @param x Initial x-coordinate of the Player.
   * @param y Initial y-coordinate of the Player.
   * @param healthPoint Initial health points of the Player.
   * @param playerSpeed Movement speed of the Player.
   * @param height Height of the Player sprite.
   * @param width Width of the Player sprite.
   * @param direct Initial direction of the Player's movement.
   */
  Player(float x, float y, int healthPoint, float playerSpeed, float height, float width, Position direct);

  /**
   * @brief Destructor for Player.
   */
  ~Player();

  /**
   * @brief Initializes the Player object with specified parameters.
   * @param x Initial x-coordinate of the Player.
   * @param y Initial y-coordinate of the Player.
   * @param healthPoint Initial health points of the Player.
   * @param spd Movement speed of the Player.
   * @param height Height of the Player sprite.
   * @param width Width of the Player sprite.
   * @param direct Initial direction of the Player's movement.
   * @return A reference to the initialized Player object.
   */
  Player InitPlayer(float x, float y, int healthPoint, float spd, float height, float width, Position direct);

  // Setter functions
  void setPos(float x, float y);
  void setHP(int healthPoint);
  void setSpeed(float speed);
  void setWidth(int w);
  void setHeight(int h);
  void setDirX(float x);
  void setDirY(float y);
  void setDir(Position p);
  void setTexture(SDL_Texture* _texture);
  void setSurface(SDL_Surface* _surface);

  // Getter functions
  SDL_Texture* getTexture();
  SDL_Surface* getSurface();
  Position getDir();
  int getHP();
  float getSpeed();
  Position getPos();
  float getWidth();
  float getHeight();


/**
   * @brief Sets the current weapon of the Player.
   * @param weapon The Weapon object to be set as the current weapon.
   */
  void setCurrentWeapon(Weapon weapon);

  /**
   * @brief Checks if enough time has passed to allow the Player to change weapons.
   * @return True if enough time has elapsed since the last weapon change, False otherwise.
   */
  bool TempsPourChanger();

  /**
   * @brief Attempts to change the Player's weapon based on user input and weapon manager availability.
   * @param weaponManager Reference to a WeaponManager object.
   * @param keyboardState Pointer to an array of Uint8 representing the current keyboard state.
   */
  void changeWeapon(WeaponManager& weaponManager, const Uint8* keyboardState);

  /**
   * @brief Checks for collisions between the Player and the game window.
   */
  void CollisionWindow();

  /**
   * @brief Gets the name of the Player's current weapon.
   * @return A string containing the name of the current weapon.
   */
  std::string getCurrentWeaponName();

  /**
   * @brief Gets the Player's current weapon object.
   * @return A reference to the Player's current Weapon object.
   */
  Weapon getCurrentWeapon();

  /**
   * @brief Checks if the Player is able to fire a projectile.
   * @return True if the Player can fire, False otherwise.
   */
  bool peutTirer(WeaponManager& weaponManager);  

  /**
   * @brief Fires a projectile from the Player's current weapon.
   * @param projectileManager Reference to a ProjectileManager object to manage the fired projectile.
   * @param weaponManager Reference to a WeaponManager object for weapon handling.
   * @param keyboardState Pointer to an array of Uint8 representing the current keyboard state.
   */
    void firePlayer(ProjectileManager& projectileManager, WeaponManager& weaponManager, const Uint8 *keyboardState, Mix_Chunk* Tirsound);

 /**
   * @brief Checks if the Player's HP are zero or less, indicating death.
   * @return True if the Player's HP is zero or less, False otherwise.
   */
  bool HPnullPlayership();

  /**
   * @brief Moves the Player's position based on user input and movement speed.
   * @param keyboardState Pointer to an array of Uint8 representing the current keyboard state.
   */
  void moveShip(const Uint8* keyboardState);

  /**
   * @brief Handles the Player's death.
   * @param projectileManager Reference to a ProjectileManager object.
   */
  void playerDeath(ProjectileManager& projectileManager);
};

#endif