#ifndef INVADERSMANAGER_H
#define INVADERSMANAGER_H

#include <vector>
#include <SDL2/SDL.h>
#include "Invaders.h"

class InvadersManager: private Invader {
private:
    int nbInvader;
    std::vector<Invader> invaders;
    std::vector<SDL_Rect> rects;

public:
    /**
     * @brief Default constructor to initialize an empty InvadersManager.
     */
    InvadersManager();

     /**
     * @brief Default constructor to initialize an empty InvadersManager.
     */
    InvadersManager(int nb);

        /**
     * @brief Default destructor to delete InvadersManager.
     */
    ~InvadersManager();

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
    void Update(ProjectileManager& tabpro, Player& player, std::vector<int> InvaderQuiTir, int indiceDuPlusADroite);

    int LePlusADroite();

    void Move(int indiceDuPlusADroite);
    
    /**
     * @brief Checks for collisions between all Invaders and a given Projectile.
     * @param P The Projectile object to check for collisions.
     * @return A vector containing indices of the hit Invaders.
     */
    void CheckCollisions(Projectile P);

    void hasInvaderCollided(Player* playerPtr);

    void DamageTakenPlayer(Player* playerPtr,Invader invader);

    /**
     * @brief Checks if all Invaders in the manager are dead.
     * @return True if all invaders are dead, False otherwise.
     */
    bool IsAllDead();

    void SetnbInvader(int nb);

    void InitTabInvader(SDL_Renderer* renderer,SDL_Surface* surfaceInvader);

    void RectInvaderInit(SDL_Renderer* renderer);  

    void RectInvaderUpdate(); 
    
    void DrawInvaders(SDL_Renderer* renderer);

    std::vector<int> QuiPeutTirer();

    void Shoot(ProjectileManager& tabpro, std::vector<int> InvaderQuiTir);

    bool ArriveEnBas();

    std::vector<Invader>* getInvaders();
};

#endif