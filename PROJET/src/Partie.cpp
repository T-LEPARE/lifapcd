#include "StarblitzGameDisplay.h"
#include "Playership.h"
#include "Invaders.h"
#include "Position.h"
#include "Projectile.h"

int main(void)
{
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Échec de l'initialisation de SDL : %s", SDL_GetError());
        return 1;
    }
    SDL_Log("SDL initialisé avec succès.");

    // Initialisation de SDL image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Log("Échec de l'initialisation de SDL_Image : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création d'une fenêtre
    SDL_Window* window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 540, 960, SDL_WINDOW_SHOWN);
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

    // Création de l'instance de Display
    
    Display display(renderer);

    // Création du playerShip
    Player player;
    player.setSurface(IMG_Load("./data/PlayerShip.png"));
    if (player.getSurface() == nullptr) {
    SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
    // Gestion de l'erreur appropriée
    }
    player.setTexture( SDL_CreateTextureFromSurface(renderer, player.getSurface()) );
    if (player.getTexture() == nullptr) {
        SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }


    // Boucle principale du jeu
    Uint32 prevTicks = SDL_GetTicks();
    const float targetFrameTime = 1000.0f / 60.0f;
    bool running = true;
    while (running) {
        Uint32 currentTicks = SDL_GetTicks();
        float deltaTime = (currentTicks - prevTicks) / 1000.0f; // Convertir en secondes
        prevTicks = currentTicks; // Mettre à jour prevTicks

        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // Autres gestionnaires d'événements si nécessaire
        }

        // Mise à jour du jeu
        display.updateGame(deltaTime, targetFrameTime);

        // Effectuer le rendu
        display.render(renderer);
    }

    // Libération des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
