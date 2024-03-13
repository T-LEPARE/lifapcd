#include "StarblitzGameDisplay.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main() {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Échec de l'initialisation de SDL : %s", SDL_GetError());
        return 1;
    }
    SDL_Log("SDL initialisé avec succès.");

    // Création d'une fenêtre
    SDL_Window* window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DIMW, DIMH, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Échec de la création de la fenêtre : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Log("Fenêtre créée avec succès.");

    // Création d'un rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Échec de la création du rendu : %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Log("Rendu créé avec succès.");

    // Chargement d'une image
    SDL_Surface* surface = IMG_Load("./data/SpaceInvaders_Background.png");
    if (surface == nullptr) {
        SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Log("Image chargée avec succès!");

    // Vérification de la création de la texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Log("Texture créée avec succès!");

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

        // Vérification que la largeur et la hauteur de la surface ne sont pas nulles
        if (surface->w != 0 && surface->h != 0) {
            // Calcul du nombre de répétitions horizontales et verticales
            int numHorizontalRepeats = (DIMW / surface->w) + 1;
            int numVerticalRepeats = (DIMH / surface->h) + 1;
            SDL_Log("Nombre de répétitions horizontales : %d", numHorizontalRepeats);
            SDL_Log("Nombre de répétitions verticales : %d", numVerticalRepeats);

            // Boucle de rendu avec affichage des coordonnées
            for (int x = 0; x < numHorizontalRepeats; ++x) {
                for (int y = 0; y < numVerticalRepeats; ++y) {
                    SDL_Rect dstRect = { x * surface->w, y * surface->h, surface->w, surface->h };
                    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                    SDL_Log("Rendu de l'image à (%d, %d)", x * surface->w, y * surface->h);
                }
            }
        } else {
            SDL_Log("La largeur ou la hauteur de la surface est nulle, impossible de calculer les répétitions.");
        }

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
