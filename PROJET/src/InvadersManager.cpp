#include "InvadersManager.h"

InvadersManager::InvadersManager() {}

void InvadersManager::AddInvader(const Invader& invader) {
    invaders.push_back(invader);
}

void InvadersManager::RemoveInvader(size_t index) {
    invaders.erase(invaders.begin() + index);
}

void InvadersManager::UpdateMovement() {
    for (Invader& invader : invaders) {
        invader.movement();
    }
}

std::vector<size_t> InvadersManager::CheckCollisions(Projectile P) {
    std::vector<size_t> hitInvaders;
    for (size_t i = 0; i < invaders.size(); i++) {
        if (invaders[i].CheckCollision(P)) {
            hitInvaders.push_back(i);
        }
    }
    return hitInvaders;
}

bool InvadersManager::IsAllDead() {
    return invaders.empty();
}