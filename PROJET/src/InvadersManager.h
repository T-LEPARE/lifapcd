#ifndef INVADERS_MANAGER_H
#define INVADERS_MANAGER_H
#include "Projectile.h"
#include "Position.h"
#include "Invaders.h"
#include <vector>

class InvadersManager: private Invader {
private:
    std::vector<Invader> invaders;

public:
    /**
     * @brief Default constructor to initialize an empty InvadersManager.
     */
    InvadersManager();

    /**
     * @brief Adds a new Invader to the vector.
     * @param invader The Invader object to be added.
     */
    void AddInvader(const Invader& invader);

    /**
     * @brief Removes a dead Invader from the vector.
     * @param index The index of the Invader to be removed.
     */
    void RemoveInvader(size_t index);

    /**
     * @brief Updates the positions of all Invaders based on their movement pattern.
     */
    void UpdateMovement();
    
    /**
     * @brief Checks for collisions between all Invaders and a given Projectile.
     * @param P The Projectile object to check for collisions.
     * @return A vector containing indices of the hit Invaders.
     */
    std::vector<size_t> CheckCollisions(Projectile P);

    /**
     * @brief Checks if all Invaders in the manager are dead.
     * @return True if all invaders are dead, False otherwise.
     */
    bool IsAllDead();

};

#endif