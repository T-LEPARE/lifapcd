#include "InvadersManager.h"


InvadersManager::InvadersManager() {
    this->nbInvader = 0;
    
}


void InvadersManager::SetnbInvader(int nb){
    this->nbInvader = nb ;
}

void InvadersManager::AddInvader(const Invader& invader) { 
    invaders.push_back(invader);
}

void InvadersManager::RemoveInvader(size_t index) {
    invaders.erase(invaders.begin() + index);
}

// void InvadersManager::UpdateMovement() {
//     for (Invader& invader : invaders) {
//         if (invader.getPos().x>=960-)
            
//         else invader.setPos(invader.getPos().x+invader.getSpeed(),invader.getPos().y);
//     }
// }

void InvadersManager::UpdateMovement() {
    for (unsigned int i = 0; i < nbInvader; i++) {
        float invaderSpeed = invaders[i].getSpeed(); // Get the speed of the current invader

        // Update the position of the invader based on its direction and speed
        float newXPos = invaders[i].getPos().x + invaderSpeed;

        // Check if the invader reaches the window boundaries
        if (newXPos < 0 || newXPos + invaders[i].getWidth() > 540) {
            // Reverse the direction of the invader
            invaderSpeed *= -1;
            invaders[i].setSpeed(invaderSpeed);
            newXPos = invaders[i].getPos().x + invaderSpeed;
        }

        // Update the position of the invader
        invaders[i].setPos(newXPos, invaders[i].getPos().y);
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

void InvadersManager::InitTabInvader(SDL_Renderer* renderer){
    float x,y;
    x=50;
    y=100;
    for(int i = 0;i<nbInvader;i++){
          // Création du Invader
    Invader invader(x,y);
    AddInvader(invader);
    invaders[i].setSurface(IMG_Load("./data/LargeAlien.png"));
    if (invaders[i].getSurface() == nullptr) {
        SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }
    invaders[i].setTexture(SDL_CreateTextureFromSurface(renderer, invaders[i].getSurface()));
    if (invaders[i].getTexture() == nullptr) {
        SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }
    x+=invaders[i].getWidth()+10;
    }
}

void InvadersManager::RectInvaderInit(SDL_Renderer* renderer){
    for (int i = 0;i<nbInvader;i++){
        rects.push_back({int(invaders[i].getPos().x),int(invaders[i].getPos().y),int(invaders[i].getWidth()),int(invaders[i].getHeight())});
    }
}

SDL_Rect InvadersManager::RectInvaderUpdate() {
    for (int i = 0; i < nbInvader; i++){ 
        rects.at(i) = {static_cast<int>(invaders[i].getPos().x), static_cast<int>(invaders[i].getPos().y), static_cast<int>(invaders[i].getWidth()), static_cast<int>(invaders[i].getHeight())};
    }
}

void InvadersManager::DrawInvaders(SDL_Renderer* renderer){
    RectInvaderUpdate();
    for (int i = 0;i<nbInvader;i++){
        SDL_RenderCopy(renderer, invaders[i].getTexture(), NULL, &rects[i]);     
    }
}