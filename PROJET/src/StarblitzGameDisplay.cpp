#include "StarblitzGameDisplay.h"

int main() {
  // Initialisation de SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_Log("Échec de l'initialisation de SDL : %s", SDL_GetError());
    return 1;
  }

  // Création d'une fenêtre
  SDL_Window* window = SDL_CreateWindow("Affichage simple avec SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DIMW, DIMH, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    SDL_Log("Échec de la création de la fenêtre : %s", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // Création d'un rendu
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    SDL_Log("Échec de la création du rendu : %s", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Chargement d'une image (remplacer "image.png" par votre fichier)
  SDL_Surface* surface = IMG_Load("./data/SpaceInvaders_Background.png");
  if (surface == nullptr) {
    SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Création d'une texture à partir de l'image
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  // Libération de la surface après création de la texture
  SDL_FreeSurface(surface);

  // Début de la boucle de jeu
bool running = true;
while (running) {
    // Gestion des événements
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Sortie de la boucle et fermeture de la fenêtre lorsque l'utilisateur quitte le jeu
        if (event.type == SDL_QUIT) {
            running = false;
        }

        // ... (Traitement des autres événements)
    }

    // Effacement de l'écran avec une couleur
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Affichage de l'image
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Mise à jour de l'écran
    SDL_RenderPresent(renderer);
}

// Nettoyage
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

  return 0;
}