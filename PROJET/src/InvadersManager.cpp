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

void InvadersManager::UpdateMovement() {
    for (int i = 0; i < nbInvader; i++) {
        invaders[i].setPos(invaders[i].getPos().x + invaders[i].getDirection().x * invaders[i].getSpeed(), invaders[i].getPos().y + invaders[i].getDirection().y * invaders[i].getSpeed());
    }

    float leftMost = invaders[0].getPos().x;
    float rightMost = invaders[nbInvader - 1].getPos().x + invaders[nbInvader - 1].getWidth();
    if (leftMost < 0 || rightMost > 540) {
        for (int i = 0; i < nbInvader; i++) {
            invaders[i].setDirection(-1*invaders[i].getDirection().x,1);
            invaders[i].setPos(invaders[i].getPos().x + invaders[i].getDirection().x * invaders[i].getSpeed(), invaders[i].getPos().y + invaders[i].getDirection().y * invaders[i].getHeight());
            invaders[i].setDirection(invaders[i].getDirection().x,0);
        }
    }
}


void InvadersManager::CheckCollisions(Projectile P) {
    for (size_t i = 0; i < invaders.size(); i++) {
        if (invaders[i].CheckCollision(P)) {
            invaders[i].DamageTaken(P);
            if(invaders[i].HPnull())
                invaders.erase(invaders.begin()+i);
        }
    }
}

bool InvadersManager::IsAllDead() {
    return invaders.empty();
}

void InvadersManager::InitTabInvader(SDL_Renderer* renderer,SDL_Surface* surfaceInvader){
    float x,y;
    x=50;
    y=100;
    for(int i = 0;i<nbInvader;i++){
          // Création du Invader
    Invader invader(x,y);
    AddInvader(invader);
    invaders[i].setSurface(surfaceInvader);
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

void InvadersManager::RectInvaderUpdate() {
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

void InvadersManager::shootEverybody(ProjectileManager tabpro){
     for (int i = 0;i<nbInvader;i++){
        invaders[i].shootInvader(tabpro);    
    }
}

bool InvadersManager::ArriveEnBas()
{
    for (unsigned int i = 0; i < nbInvader; i++) {
        if(invaders[i].ArriveEnBas())
            return true;
    }
    return false;
}
