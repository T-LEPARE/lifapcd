#include "StarblitzGameDisplay.h"

int Display::DIMW;
int Display::DIMH;

Display::Display(SDL_Renderer* renderer){
 // Initialisation des membres
    setDIMW(540);
    setDIMH(960);
    prevTicks = SDL_GetTicks();
    targetFrameTime = 1000.0f / 60.0f; // Cible de 60 FPS

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

/*void Display::updateGame(float deltaTime, float targetFrameTime) {
    // Mesurer le temps écoulé depuis le dernier frame
    Uint32 currentTicks = SDL_GetTicks();
    if (currentTicks - prevTicks >= targetFrameTime) {
        // Si le temps écoulé dépasse le temps cible, faire quelque chose
        prevTicks = currentTicks; // Mettre à jour le temps précédent
    }

    // Mettre ici la logique du jeu qui doit être mise à jour à chaque frame
    //SDL_Log("Jeu mis à jour");

}*/

void Display::render(SDL_Renderer* renderer) {
  // Effacer l'écran avec une couleur (optional, keep it for now)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);
  int numRepeatsX = (DIMW / surface->w)+1;
  int numRepeatsY = (DIMH / surface->h)+1;

for (int y = 0; y < numRepeatsY; ++y) {
    for (int x = 0; x < numRepeatsX; ++x) {
      // Define the rectangle for each image position
      SDL_Rect rect = {x * surface->w, y * surface->h, surface->w, surface->h};
      SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
  }

  // Mettre à jour l'écran
  SDL_RenderPresent(renderer);
}