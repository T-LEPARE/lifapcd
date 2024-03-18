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

void Display::updateGame(float deltaTime, float targetFrameTime) {
    // Mesurer le temps écoulé depuis le dernier frame
    Uint32 currentTicks = SDL_GetTicks();
    if (currentTicks - prevTicks >= targetFrameTime) {
        // Si le temps écoulé dépasse le temps cible, faire quelque chose
        prevTicks = currentTicks; // Mettre à jour le temps précédent
    }

    // Mettre ici la logique du jeu qui doit être mise à jour à chaque frame
    //SDL_Log("Jeu mis à jour");

}

void Display::render(SDL_Renderer* renderer) {
    // Effacer l'écran avec une couleur
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.w = surface->w;
    rect.h = surface->h;

    // Render the image repeatedly horizontally and vertically
    for (int y = 0; y < DIMH; y += surface->h) {
        for (int x = 0; x < DIMW; x += surface->w) {
        rect.x = x;
        rect.y = y;
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }
    // Mettre à jour l'écran
    SDL_RenderPresent(renderer);
}

int main() {
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
    player.surface = IMG_Load("./data/PlayerShip.png");
    if (player.surface == nullptr) {
    SDL_Log("Échec du chargement de l'image : %s", SDL_GetError());
    // Gestion de l'erreur appropriée
    }
    player.texture = SDL_CreateTextureFromSurface(renderer, player.surface);
    if (player.texture == nullptr) {
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
