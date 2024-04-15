#include "InvadersManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


InvadersManager::InvadersManager() {
    this->nbInvader = 0;
}

InvadersManager::~InvadersManager() {
    invaders.clear();
    rects.clear();
}


void InvadersManager::SetnbInvader(int nb){
    this->nbInvader = nb ;
}

void InvadersManager::SetNumVague(int num){
    this->vague = num ;
}

int InvadersManager::GetNumVague(){
    return vague;
}

void InvadersManager::AddInvader(const Invader& invader) { 
    invaders.push_back(invader);
}

void InvadersManager::RemoveInvader(size_t index) {
    invaders.erase(invaders.begin() + index);
}

void InvadersManager::Update(ProjectileManager& tabpro, Player &player, std::vector<int> InvaderQuiTir,int indiceDuPlusADroite) {
    Shoot(tabpro, InvaderQuiTir);
    hasInvaderCollided(&player);
    Move(indiceDuPlusADroite);
}

std::vector<int> InvadersManager::QuiPeutTirer()
{
    std::vector<int> DerniereLigne;
    Invader reference=invaders[nbInvader-1];
    for(int i=0;i<nbInvader;i++)
    {
        if (invaders[i].getPos().y==reference.getPos().y)
        {
            DerniereLigne.push_back(i);
        }
    }
    return DerniereLigne;
}

void InvadersManager::Shoot(ProjectileManager& tabpro,std::vector<int> InvaderQuiTir ){
    std::srand(time(NULL));
    int CeluiQuiTir = std::rand()%InvaderQuiTir.size(); 
    invaders[InvaderQuiTir[CeluiQuiTir]].shootInvader(tabpro);
}


int InvadersManager::LePlusADroite()
{
    float reference=0;
    for (int i = 0; i < nbInvader; i++) 
    {
        if(invaders[i].getPos().x>invaders[reference].getPos().x)
            reference=i;
    }
    return reference;
}

void InvadersManager::Move(int indiceDuPlusADroite) {
    float leftMost = invaders[0].getPos().x;
    float rightMost = invaders[indiceDuPlusADroite].getPos().x + invaders[indiceDuPlusADroite].getWidth();
    if (leftMost < 0 || rightMost > 540) {
        for (int i = 0; i < nbInvader; i++) {
            invaders[i].setDirection(-1*invaders[i].getDirection().x,1);
            invaders[i].setPos(invaders[i].getPos().x + invaders[i].getDirection().x * invaders[i].getSpeed(), invaders[i].getPos().y + invaders[i].getDirection().y * invaders[i].getHeight());
            invaders[i].setDirection(invaders[i].getDirection().x,0);
        }
    } else
    {
        for (int i = 0; i < nbInvader; i++) {
            invaders[i].setPos(invaders[i].getPos().x + invaders[i].getDirection().x * invaders[i].getSpeed(), invaders[i].getPos().y + invaders[i].getDirection().y * invaders[i].getSpeed());
            if(invaders[i].HPnullInvader()){
                invaders.erase(invaders.begin()+i);
                nbInvader--;
                i--;
            }
        }
    }
}

bool InvadersManager::InvaderDead()
{
    for (int i = 0; i < nbInvader; i++) {
            if(invaders[i].HPnullInvader())
                return true;
    }
    return false;
}

void InvadersManager::hasInvaderCollided(Player* playerPtr)
{
    for(int i=0;i<nbInvader;i++)
    {
        Position Iposition = invaders[i].getPos();
        Position Pposition = playerPtr->getPos();
        if ((Iposition.x < Pposition.x+ playerPtr->getWidth()) &&
            (Iposition.x + invaders[i].getWidth() > Pposition.x ) &&
            (Iposition.y < Pposition.y + playerPtr->getHeight()) &&
            (Iposition.y + invaders[i].getHeight()> Pposition.y ))
            {
                Uint32 maintenant = SDL_GetTicks();
                if (maintenant - Dernier_PerteDeVie > 50)
                {
                    Dernier_PerteDeVie = maintenant;
                    DamageTakenPlayer(playerPtr,invaders[i]);
                }
            }
    }
}

void InvadersManager::DamageTakenPlayer(Player* playerPtr,Invader invader)
{
    int dmg = invader.getDamage();
    playerPtr->setHP(playerPtr->getHP() - dmg);
    std::cout << "playerHP = " << playerPtr->getHP() << std::endl;
}

bool InvadersManager::IsAllDead() {
    return invaders.empty();
}

void InvadersManager::InitTabInvader(SDL_Renderer* renderer,SDL_Surface* surfaceInvader){
    if (surfaceInvader != nullptr) {
    SDL_Texture* invaderTexture = SDL_CreateTextureFromSurface(renderer, surfaceInvader);
    float x,y;
    x=50;
    y=100;
    float NvHP = 10*vague;
    int Nvdmg = 5*vague;
    for (int i = 0;i<nbInvader;i++) {
        // Création de l'invader
        Invader invader(x,y,NvHP,Nvdmg);
        AddInvader(invader);
        invaders[i].setSurface(surfaceInvader);
        invaders[i].setTexture(invaderTexture);
        if (invaders[i].getTexture() == nullptr) {
            SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        if (x+invaders[i].getWidth()+10>=400)
            {x=-10;y+=invaders[i].getHeight()+10;}
        x+=invaders[i].getWidth()+10;
    }
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

bool InvadersManager::ArriveEnBas()
{
    if(invaders[nbInvader-1].ArriveEnBas())
            return true;
    return false;
}

std::vector<Invader>* InvadersManager::getInvaders(){
    return &invaders;
}

void InvadersManager::resetInvaders() {
    invaders.clear();
    rects.clear();
    nbInvader = 0;
}