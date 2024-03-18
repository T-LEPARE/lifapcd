#ifndef STARBLITZGAMEDISPLAY_H
#define STARBLITZGAMEDISPLAY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Playership.h"

class Display {
private:
    static int DIMW;
    static int DIMH;
    Uint32 prevTicks;
    float targetFrameTime;
    SDL_Surface* surface;
    SDL_Texture* texture;

public:
    Display(SDL_Renderer* _renderer);
    ~Display();
    static int getDIMW();
    static int getDIMH();
    static void setDIMW(int DIMW);
    static void setDIMH(int DIMH);
    void updateGame(float dT, float targetTime);  // Fonction pour mettre à jour le jeu en fonction du delta temps
    bool shouldRender;
    void render(SDL_Renderer* renderer); // Effectue le rendu

};

#endif