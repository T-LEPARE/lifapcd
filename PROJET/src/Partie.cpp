#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Playership.h"
#include "Position.h"
#include "Projectile.h"
#include "InvadersManager.h"
#include "StarblitzGameDisplay.h"
#include "ProjectileManager.h"
#include "WeaponManager.h"
#include "Weapon.h"
#include <memory>

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
    player.setTexture(SDL_CreateTextureFromSurface(renderer, player.getSurface()));
    if (player.getTexture() == nullptr) {
        SDL_Log("Échec de la création de la texture : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }
    // Création du tab invader
    SDL_Surface* surfaceInvader = IMG_Load("./data/LargeAlien.png");
    if ( surfaceInvader == nullptr) {
        SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
        // Gestion de l'erreur appropriée
    }
    InvadersManager itab;
    ProjectileManager Pmanager;
    WeaponManager weaponManager;
    std::cout << "weaponManager Initialised" << std::endl;

    // Boucle principale du jeu
    bool running = true;
    SDL_Event event;
    const int targetFPS = 60;
    const float targetFrameTime = 1000.0f / targetFPS;  // milliseconds per frame
    float elapsed;
    float delay;

    while (running) {
        Uint64 start = SDL_GetPerformanceCounter();
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            player.movement(event); 
            player.CollisionWindow();
            }
            SDL_Rect playerRect = {int(player.getPos().x), int(player.getPos().y), int(player.getWidth()), int(player.getHeight())};
            if(itab.IsAllDead()){
                std::cout<<"It's empty !"<<std::endl;
                itab.SetnbInvader(4);
                itab.InitTabInvader(renderer,surfaceInvader);
                itab.RectInvaderInit(renderer);
                if (itab.IsAllDead()==1) {
                    std::cout << "still empty" << std::endl;
                } else {std::cout << "not empty anymore" << std::endl;}
            }
            
            // Render the game state
            // Effacer l'écran avec une couleur
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);
            int numRepeatsX = (display.getDIMW() / display.getSurface()->w)+1;
            int numRepeatsY = (display.getDIMH() / display.getSurface()->h)+1;

            for (int y = 0; y < numRepeatsY; y++) {
                for (int x = 0; x < numRepeatsX; x++) {
                // Define the rectangle for each image position
                SDL_Rect rect = {x * display.getSurface()->w, y * display.getSurface()->h, display.getSurface()->w, display.getSurface()->h};
                SDL_RenderCopy(renderer, display.getTexture(), NULL, &rect);
                }
            }
            std::vector<Invader>* itabPtr = itab.getInvaders();
            itab.UpdateMovement();
            SDL_RenderCopy(renderer, player.getTexture(), NULL, &playerRect);
            itab.DrawInvaders(renderer);
            player.firePlayer(Pmanager, weaponManager);
            Pmanager.UpdateProj();
            Pmanager.hasProjectileCollided(&player,itabPtr);
            Pmanager.DrawProj(renderer);
            // Present the rendered frame
            SDL_RenderPresent(renderer);

            Uint64 end = SDL_GetPerformanceCounter();

	        elapsed = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

            delay = targetFrameTime - elapsed;
            if (delay > 0) {
                SDL_Delay(floor(delay));
            }
    }

    // Libération des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
