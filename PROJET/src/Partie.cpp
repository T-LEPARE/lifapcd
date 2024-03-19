#include "StarblitzGameDisplay.h"
#include "Playership.h"
#include "Invaders.h"
#include "Position.h"
#include "Projectile.h"

int main(void)
{
    SDL_Renderer* renderer;
    Display display(renderer);
    display.main(display);
}