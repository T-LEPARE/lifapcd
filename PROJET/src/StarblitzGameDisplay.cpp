#include "StarblitzGameDisplay.h"

int Display::DIMW;
int Display::DIMH;

Display::Display(SDL_Renderer* renderer){
 // Initialisation des membres
    setDIMW(540);
    setDIMH(960);

    // Chargement de l'image
    surface = IMG_Load("./data/SpaceInvaders_Background.png");
    if (surface == nullptr) {
        SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }

    // Création de la texture à partir de la surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }
}

Display::~Display(){
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
}

int Display::getDIMW(){
    return DIMW;
}

int Display::getDIMH(){
    return DIMH;
}

void Display::setDIMW(int _DIMW){
    DIMW = _DIMW;
}

void Display::setDIMH(int _DIMH){
    DIMH = _DIMH;
}

SDL_Texture* Display::getTexture(){
        return texture;
}
SDL_Surface* Display::getSurface(){
        return surface;
}
void Display::setTexture(SDL_Texture* _texture){
        texture = _texture;
}
void Display::setSurface(SDL_Surface* _surface){
        surface = _surface;
}


void Display::render(SDL_Renderer* renderer) {

}