#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Playership.h"
#include "Invaders.h"
#include "StarblitzGameDisplay.h"  // Assuming this provides display dimensions

class Player;
class Invader;

class ProjectileManager {
private:
  std::vector<std::unique_ptr<Projectile>> projectiles;

public:
  /**
   * @brief Default constructor for ProjectileManager. Initializes an empty projectile vector.
   */
  ProjectileManager();

  /**
   * @brief Destructor for ProjectileManager. Frees resources (projectiles) held in the vector.
   */
  ~ProjectileManager();

  /**
   * @brief Sets the maximum number of projectiles that can be managed (not implemented in the provided code).
   * @param nb The intended maximum number of projectiles.
   */
  void SetnbProjectile(int nb);

  /**
   * @brief Gets the current number of projectiles managed by the ProjectileManager.
   * @return The number of projectiles in the internal vector.
   */
  int GetnbProjectile();

  /**
   * @brief Adds a new Projectile object to the manager.
   * @param projectile A unique_ptr owning the Projectile object to be added.
   */
  void addProjectile(std::unique_ptr<Projectile> projectile);

  /**
   * @brief Removes a specific Projectile object from the manager based on a provided pointer.
   * @param projectileToRemove A unique_ptr referencing the Projectile object to be removed.
   */
  void removeProjectiles(const std::unique_ptr<Projectile>& projectileToRemove);

  /**
   * @brief Handles potential damage taken by a Player or Invader from a Projectile.
   * @param projectilePtr Unique_ptr referencing the Projectile object.
   * @param playerPtr Pointer to a Player object (can be nullptr if not involved in collision).
   * @param invaderPtr Pointer to an Invader object (can be nullptr if not involved in collision).
   */
  void DamageTakenProjectile(std::unique_ptr<Projectile>& projectilePtr, Player* playerPtr, Invader* invaderPtr);

  /**
   * @brief Checks if a Projectile is outside the playable area defined by display dimensions.
   * @param projectile A const reference to a unique_ptr holding the Projectile object.
   * @return True if the Projectile is outside the display area, False otherwise.
   */
  bool isProjectileOutOfBounds(const std::unique_ptr<Projectile>& projectile) const;

  /**
   * @brief Checks for collisions between projectiles and Invaders or the Player.
   * @param playerPtr Pointer to a Player object.
   * @param invaders Pointer to a vector containing Invader objects.
   */
  void hasProjectileCollided(Player* playerPtr, std::vector<Invader>* invaders);

  /**
   * @brief Draws all managed Projectiles on the specified renderer.
   * @param renderer Reference to an SDL_Renderer object.
   */
  void DrawProj(SDL_Renderer* renderer);

  /**
   * @brief Updates the positions of all managed Projectiles.
   * 
   * This function iterates through the projectiles, updates their positions, and removes any that are out of bounds.
   */
  void UpdateProj();

  /**
   * @brief Clears the internal vector of projectiles, removing all managed projectiles.
   */
  void clearTab();
};

#endif