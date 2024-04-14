#ifndef INVADERSMANAGER_H
#define INVADERSMANAGER_H

#include <vector>
#include <SDL2/SDL.h>
#include "Invaders.h"
#include "ScoreSystem.h"

class InvadersManager: private Invader {
private:
  int nbInvader;
  Uint32 Dernier_PerteDeVie;
  std::vector<Invader> invaders;
  std::vector<SDL_Rect> rects;

public:
  /**
   * @brief Default constructor to initialize an empty InvadersManager.
   */
  InvadersManager();

  /**
   * @brief Constructor to initialize an InvadersManager with a specified number of invaders.
   * @param nb The number of invaders to create.
   */
  InvadersManager(int nb);

  /**
   * @brief Destructor to delete the InvadersManager and its resources.
   */
  ~InvadersManager();

  /**
   * @brief Adds a new Invader object to the internal vector.
   * @param invader The Invader object to be added.
   */
  void AddInvader(const Invader& invader);

  /**
   * @brief Removes a dead Invader from the internal vector based on its index.
   * @param index The index of the Invader to be removed.
   */
  void RemoveInvader(size_t index);

  /**
   * @brief Updates the positions of all Invaders based on their movement pattern.
   * @param tabpro Reference to a ProjectileManager object.
   * @param player Reference to a Player object.
   * @param InvaderQuiTir Vector containing indices of invaders that can shoot.
   * @param indiceDuPlusADroite Index of the rightmost Invader.
   */
  void Update(ProjectileManager& tabpro, Player& player, std::vector<int> InvaderQuiTir, int indiceDuPlusADroite);

  /**
   * @brief Finds the index of the rightmost Invader.
   * @return The index of the rightmost Invader.
   */
  int LePlusADroite();

  /**
   * @brief Moves all Invaders a certain distance based on the index of the rightmost Invader.
   * @param indiceDuPlusADroite Index of the rightmost Invader.
   */
  void Move(int indiceDuPlusADroite);

  /**
   * @return If an invader is dead
   */
  bool InvaderDead();

  /**
   * @brief Checks for collisions between all Invaders and a given Projectile.
   * @param P The Projectile object to check for collisions.
   * @return A vector containing indices of the hit Invaders.
   */
  void CheckCollisions(Projectile P);

  /**
   * @brief Checks if the player is currently invulnerable due to taking damage.
   * @return True if the player is invulnerable, False otherwise.
   */
  bool PlayerDelayDmg();

  /**
   * @brief Checks for collision between a specific Invader and the Player.
   * @param playerPtr Pointer to a Player object.
   */
  void hasInvaderCollided(Player* playerPtr);

  /**
   * @brief Handles damage taken by the Player from a specific Invader.
   * @param playerPtr Pointer to a Player object.
   * @param invader The Invader object that inflicted the damage.
   */
  void DamageTakenPlayer(Player* playerPtr,Invader invader);

  /**
   * @brief Checks if all Invaders in the manager are dead.
   * @return True if all invaders are dead, False otherwise.
   */
  bool IsAllDead();

  /**
   * @brief Sets the number of Invaders to manage.
   * @param nb The number of Invaders.
   */
  void SetnbInvader(int nb);

  /**
   * @brief Initializes the internal vector of Invaders with specified renderer and surface.
   * @param renderer Reference to an SDL_Renderer object.
   * @param surfaceInvader Reference to an SDL_Surface object containing the Invader image.
   */
  void InitTabInvader(SDL_Renderer* renderer,SDL_Surface* surfaceInvader);

  /**
   * @brief Initializes the internal vector of rectangles representing the Invader positions.
   * @param renderer Reference to an SDL_Renderer object.
   */
  void RectInvaderInit(SDL_Renderer* renderer);

 /**
   * @brief Updates the positions of the rectangles representing the Invader positions.
   */
  void RectInvaderUpdate();

  /**
   * @brief Draws all Invaders on the specified renderer.
   * @param renderer Reference to an SDL_Renderer object.
   */
  void DrawInvaders(SDL_Renderer* renderer);

  /**
   * @brief Determines which Invaders are able to shoot based on their position and other factors.
   * @return A vector containing indices of the Invaders that can shoot.
   */
  std::vector<int> QuiPeutTirer();

  /**
   * @brief Makes Invaders that can shoot fire projectiles.
   * @param tabpro Reference to a ProjectileManager object.
   * @param InvaderQuiTir Vector containing indices of invaders that can shoot.
   */
  void Shoot(ProjectileManager& tabpro, std::vector<int> InvaderQuiTir);

  /**
   * @brief Checks if any Invaders have reached the bottom of the screen.
   * @return True if any Invader has reached the bottom, False otherwise.
   */
  bool ArriveEnBas();

  /**
   * @brief Getter function to access the internal vector of Invaders.
   * @return A pointer to the vector containing the Invader objects.
   */
  std::vector<Invader>* getInvaders();

  /**
   * @brief Resets the InvadersManager to its initial state.
   */
  void resetInvaders();
};

#endif