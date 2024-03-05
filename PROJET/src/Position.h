#ifndef POSITION_H
#define POSITION_H

struct Position{
    float x;
    float y;

    /**
     @brief constructeur de position
     @param x position x
     @param x position y
     @return retourne la position (x,y)
    */
   Position();
   Position (float x, float y);
};

#endif