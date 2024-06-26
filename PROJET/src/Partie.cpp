#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "Playership.h"
#include "Position.h"
#include "Projectile.h"
#include "InvadersManager.h"
#include "StarblitzGameDisplay.h"
#include "ProjectileManager.h"
#include "WeaponManager.h"
#include "Weapon.h"
#include "ScoreSystem.h"
#include <memory>




enum class GameState {
    Menu,
    Running,
    Exiting,
    Paused,
    loosescreen,
};





int main(void)
{
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Échec de l'initialisation de SDL : %s", SDL_GetError());
        return 1;
    }
    SDL_Log("SDL initialisé avec succès.");
    // Initialisation de SDL_ttf
if (TTF_Init() != 0) {
    SDL_Log("Échec de l'initialisation de SDL_ttf : %s", TTF_GetError());
    SDL_Quit();
    return 1;
}
 TTF_Font* font = TTF_OpenFont("./data/space_invaders.ttf", 24);
    if (font == nullptr) {
        return 1;
    }


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Erreur lors de l'initialisation de SDL Mixer : " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Charger les sons
    Mix_Chunk* tirSound = Mix_LoadWAV("./data/LaserGun.wav");
    if (tirSound == nullptr) {
        std::cerr << "Erreur lors du chargement du son : " << Mix_GetError() << std::endl;
        Mix_Quit();
        SDL_Quit();
        return 1;
    }

    Mix_Chunk* SoundDmg = Mix_LoadWAV("./data/SoundDmgV2.wav");
    if (SoundDmg == nullptr) {
        std::cerr << "Erreur lors du chargement du son : " << Mix_GetError() << std::endl;
        Mix_Quit();
        SDL_Quit();
        return 1;
    }

    // Charger la musique de fond
    Mix_Music* backgroundMusic = Mix_LoadMUS("./data/Space_Invaders.wav");
    if (backgroundMusic == nullptr) {
        std::cerr << "Erreur lors du chargement de la musique de fond : " << Mix_GetError() << std::endl;
        Mix_FreeChunk(tirSound);
        Mix_FreeChunk(SoundDmg);
        Mix_Quit();
        SDL_Quit();
        return 1;
    }




    // Attendre que la musique se termine (ou ajouter de la logique pour continuer à jouer)

    // Initialisation de SDL image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        SDL_Log("Échec de l'initialisation de SDL_Image : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création d'une fenêtre
    SDL_Window* window = SDL_CreateWindow("StarBlitz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 540, 960, SDL_WINDOW_SHOWN);
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
    
    SDL_Surface* vie1Surface = IMG_Load("./data/SpaceInvaders_Health_1.png");
    SDL_Surface* vie2Surface = IMG_Load("./data/SpaceInvaders_Health_2.png");
    SDL_Surface* vie3Surface = IMG_Load("./data/SpaceInvaders_Health_3.png");
    SDL_Surface* vie4Surface = IMG_Load("./data/SpaceInvaders_Health_4.png");
    SDL_Surface* vie5Surface = IMG_Load("./data/SpaceInvaders_Health_5.png");
    SDL_Surface* vie0Surface = IMG_Load("./data/SpaceInvaders_Health_0.png");
    SDL_Texture* vieTexture;
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
    ScoreSystem score;
    char scoreTexte[20];
    char numvague[20];
    std::cout << "weaponManager Initialised" << std::endl;

    // Boucle principale du jeu
    GameState gameState = GameState::Menu;
    bool running = true;
    SDL_Event event;
    const int targetFPS = 60;
    const float targetFrameTime = 1000.0f / targetFPS;  // milliseconds per frame
    float elapsed;
    float delay;
        while (running) {
        Uint64 start = SDL_GetPerformanceCounter();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            if (gameState == GameState::Menu) {
                // Gestion des événements du menu
                if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        gameState = GameState::Running;
                        Mix_PlayMusic(backgroundMusic, -1);
                        score.init();
                        player.setHP(0);
                        itab.resetInvaders();
                        player.playerDeath(Pmanager);
                        itab.SetnbInvader(12);
                        itab.SetNumVague(1);
                        itab.InitTabInvader(renderer,surfaceInvader);
                        itab.RectInvaderInit(renderer); // Commence le jeu si l'utilisateur appuie sur Entrée
                    } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                        gameState = GameState::Exiting; // Quitte le jeu si l'utilisateur appuie sur Échap dans le menu
                        running = false;
                    }
                }
            } else if (gameState == GameState::Running) {
                if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        gameState = GameState::Paused;
                        Mix_PauseMusic(); 
                    }
                }
            }else if (gameState == GameState::Paused){
                if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_RETURN){
                        Mix_PlayMusic(backgroundMusic, -1);
                        gameState = GameState::Running;}
                    else if(event.key.keysym.sym == SDLK_ESCAPE){
                        gameState = GameState::Menu;
                        
                    }
                    
                }
            }else if (gameState == GameState::loosescreen){
                if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        gameState = GameState::Menu;
                        
                    }
                    
                }
            }
            
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (gameState == GameState::Menu) {
            // Affichage du menu
            // Par exemple, affichez du texte pour indiquer à l'utilisateur de démarrer le jeu
            // Vous pouvez utiliser SDL_Renderer pour dessiner des éléments du menu
            // Exemple :
            int numRepeatsX = (display.getDIMW() / display.getSurface()->w)+1;
            int numRepeatsY = (display.getDIMH() / display.getSurface()->h)+1;
             for (int y = 0; y < numRepeatsY; y++) {
                for (int x = 0; x < numRepeatsX; x++) {
                // Define the rectangle for each image position
                SDL_Rect rect = {x * display.getSurface()->w, y * display.getSurface()->h, display.getSurface()->w, display.getSurface()->h};
                SDL_RenderCopy(renderer, display.getTexture(), NULL, &rect);
                }
            }
            SDL_Surface* menuSurface = IMG_Load("./data/SpaceInvaders_LogoLarge.png");
            SDL_Texture* menuTexture =SDL_CreateTextureFromSurface(renderer, menuSurface);
            SDL_Rect paused = {-45,display.getDIMW()/2,menuSurface->w,menuSurface->h};
            SDL_Color textColor = {255, 255, 255, 255};
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Press enter to start", textColor);
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

            SDL_Rect textRect = {110, 520, textSurface->w, textSurface->h};
            SDL_RenderCopy(renderer,menuTexture,NULL,&paused);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            SDL_FreeSurface(menuSurface);
            SDL_DestroyTexture(menuTexture);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
                SDL_DestroyTexture(vieTexture);


  
        }else if (gameState == GameState::loosescreen) {
            // Affichage du menu
            // Par exemple, affichez du texte pour indiquer à l'utilisateur de démarrer le jeu
            // Vous pouvez utiliser SDL_Renderer pour dessiner des éléments du menu
            // Exemple :
            vieTexture =  SDL_CreateTextureFromSurface(renderer, vie0Surface);
            SDL_Rect Vie0Rect = {0, 0, 100, 50};
            SDL_RenderCopy(renderer, vieTexture, NULL, &Vie0Rect);
            SDL_Color textColor = {255, 255, 255, 255};
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, "You died fucking idiot", textColor);
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect textRect = {110,display.getDIMH()/2, textSurface->w, textSurface->h};
            sprintf(scoreTexte, "Score : %d", score.getScore());
            SDL_Color scoreColor = {255, 255, 255, 255};
            SDL_Surface* scoreSurface = TTF_RenderText_Solid(font,scoreTexte, scoreColor);
            SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
            SDL_Rect scoreRect = {430, 0, 100, 25};
            sprintf(numvague, "Wave : %d", itab.GetNumVague());
            SDL_Color waveColor = {255, 255, 255, 255};
            SDL_Surface* waveSurface = TTF_RenderText_Solid(font,numvague, waveColor);
            SDL_Texture* waveTexture = SDL_CreateTextureFromSurface(renderer, waveSurface);
            SDL_Rect waveRect = {430, 20, 100, 25};
            SDL_RenderCopy(renderer, waveTexture, NULL, &waveRect);
            SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
            SDL_DestroyTexture(scoreTexture);
            SDL_DestroyTexture(waveTexture);
            SDL_FreeSurface(scoreSurface);
            SDL_FreeSurface(waveSurface);
  
        }  else if (gameState == GameState::Paused) {
            // Affichage du menu
            // Par exemple, affichez du texte pour indiquer à l'utilisateur de démarrer le jeu
            // Vous pouvez utiliser SDL_Renderer pour dessiner des éléments du menu
            // Exemple :
            //SpaceInvaders_LogoLarge.png
            int numRepeatsX = (display.getDIMW() / display.getSurface()->w)+1;
            int numRepeatsY = (display.getDIMH() / display.getSurface()->h)+1;
             for (int y = 0; y < numRepeatsY; y++) {
                for (int x = 0; x < numRepeatsX; x++) {
                // Define the rectangle for each image position
                SDL_Rect rect = {x * display.getSurface()->w, y * display.getSurface()->h, display.getSurface()->w, display.getSurface()->h};
                SDL_RenderCopy(renderer, display.getTexture(), NULL, &rect);
                }
            }
            itab.DrawInvaders(renderer);
            Pmanager.DrawProj(renderer);
            SDL_Rect playerRect = {int(player.getPos().x), int(player.getPos().y), int(player.getWidth()), int(player.getHeight())};
            SDL_RenderCopy(renderer, player.getTexture(), NULL, &playerRect);
            SDL_Surface* pausedSurface = IMG_Load("./data/SpaceInvaders_LogoLarge.png");
            SDL_Texture* pausedTexture =SDL_CreateTextureFromSurface(renderer, pausedSurface);
            SDL_Color textColor = {255, 255, 255, 255};
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Press enter to resume", textColor);
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect textRect = {110, 520, textSurface->w, textSurface->h};
            SDL_Rect paused = {-45,display.getDIMW()/2,pausedSurface->w,pausedSurface->h};
            sprintf(scoreTexte, "Score : %d", score.getScore());
            SDL_Color scoreColor = {255, 255, 255, 255};
            SDL_Surface* scoreSurface = TTF_RenderText_Solid(font,scoreTexte, scoreColor);
            SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
            SDL_Rect scoreRect = {430, 0, 100, 25};
                        if(player.getHP()>= 80){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie5Surface);
                SDL_Rect Vie5Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie5Rect);
            }
            else if (player.getHP() >= 60 && player.getHP()< 80){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie4Surface);
                SDL_Rect Vie4Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie4Rect);
            }
            else if (player.getHP() >= 40 && player.getHP() < 60){
               SDL_Texture* vieTexture =  SDL_CreateTextureFromSurface(renderer, vie3Surface);
                SDL_Rect Vie3Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie3Rect);
            }
            else if (player.getHP() >= 20 && player.getHP() < 40){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie2Surface);
                SDL_Rect Vie2Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie2Rect);
            }
            else if (player.getHP() >= 1 && player.getHP() < 20){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie1Surface);
                SDL_Rect Vie1Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie1Rect);
            }
            sprintf(numvague, "Wave : %d", itab.GetNumVague());
            SDL_Color waveColor = {255, 255, 255, 255};
            SDL_Surface* waveSurface = TTF_RenderText_Solid(font,numvague, waveColor);
            SDL_Texture* waveTexture = SDL_CreateTextureFromSurface(renderer, waveSurface);
            SDL_Rect waveRect = {430, 20, 100, 25};
            SDL_RenderCopy(renderer, waveTexture, NULL, &waveRect);
            SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
            SDL_RenderCopy(renderer,pausedTexture,NULL,&paused);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            SDL_FreeSurface(pausedSurface);
            SDL_DestroyTexture(pausedTexture);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
            
        } 
        else if (gameState == GameState::Running) {

             
            SDL_Rect playerRect = {int(player.getPos().x), int(player.getPos().y), int(player.getWidth()), int(player.getHeight())};
            const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
            player.moveShip(keyboardState);
            if(itab.IsAllDead()){
                std::cout<<"It's empty !"<<std::endl;
                itab.SetnbInvader(12);
                itab.SetNumVague(itab.GetNumVague()+1);
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
            if(itab.ArriveEnBas()){
                player.setHP(0);
            }
            if(player.HPnullPlayership()){
                gameState = GameState::loosescreen;
                Mix_PauseMusic();
            }
            if(player.getHP()>= 80){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie5Surface);
                SDL_Rect Vie5Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie5Rect);
            }
            else if (player.getHP() >= 60 && player.getHP()< 80){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie4Surface);
                SDL_Rect Vie4Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie4Rect);
            }
            else if (player.getHP() >= 40 && player.getHP() < 60){
               SDL_Texture* vieTexture =  SDL_CreateTextureFromSurface(renderer, vie3Surface);
                SDL_Rect Vie3Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie3Rect);
            }
            else if (player.getHP() >= 20 && player.getHP() < 40){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie2Surface);
                SDL_Rect Vie2Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie2Rect);
            }
            else if (player.getHP() >= 1 && player.getHP() < 20){
                vieTexture =  SDL_CreateTextureFromSurface(renderer, vie1Surface);
                SDL_Rect Vie1Rect = {0, 0, 100, 50};
                SDL_RenderCopy(renderer, vieTexture, NULL, &Vie1Rect);
            }
            std::vector<Invader>* itabPtr = itab.getInvaders();
            std::vector<int> ListeDerniereLigne=itab.QuiPeutTirer();
            int indiceDuPlusADroite=itab.LePlusADroite();
            if(itab.InvaderDead())
                score.incrementScore(100);
            itab.Update(Pmanager,player,ListeDerniereLigne,indiceDuPlusADroite);
            sprintf(scoreTexte, "Score : %d", score.getScore());
            SDL_Color scoreColor = {255, 255, 255, 255};
            SDL_Surface* scoreSurface = TTF_RenderText_Solid(font,scoreTexte, scoreColor);
            SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
            SDL_Rect scoreRect = {430, 0, 100, 25};
            SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
            sprintf(numvague, "Wave : %d", itab.GetNumVague());
            SDL_Color waveColor = {255, 255, 255, 255};
            SDL_Surface* waveSurface = TTF_RenderText_Solid(font,numvague, waveColor);
            SDL_Texture* waveTexture = SDL_CreateTextureFromSurface(renderer, waveSurface);
            SDL_Rect waveRect = {430, 20, 100, 25};
            SDL_RenderCopy(renderer, waveTexture, NULL, &waveRect);
            SDL_RenderCopy(renderer, player.getTexture(), NULL, &playerRect);
            itab.DrawInvaders(renderer);
            player.firePlayer(Pmanager, weaponManager,keyboardState, tirSound);
            player.changeWeapon(weaponManager,keyboardState);
            Pmanager.UpdateProj();
            Pmanager.hasProjectileCollided(&player,itabPtr,SoundDmg);
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

        SDL_RenderPresent(renderer);
        SDL_Delay(1); // Adding delay to allow for CPU to switch to another task, reducing CPU charge
    }


    // Libération des ressources
    SDL_FreeSurface(surfaceInvader);
    SDL_FreeSurface(vie1Surface);
    SDL_FreeSurface(vie2Surface);
    SDL_FreeSurface(vie3Surface);
    SDL_FreeSurface(vie4Surface);
    SDL_FreeSurface(vie5Surface);
    SDL_FreeSurface(vie0Surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    Mix_FreeChunk(tirSound);
    Mix_FreeMusic(backgroundMusic);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();

    return 0;
}
