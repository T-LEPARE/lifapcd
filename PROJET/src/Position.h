#ifndef POSITION_H
#define POSITION_H

struct positions
{
  float x;
  float y;
};


class Position{
  private:
  positions xy;

  /**
   * @brief constructeur de position
   * @param x position x
   * @param x position y
   */
  Position();
  Position (float x, float y);

  public:
  /**
   * @return renvoie la position X
   */
  float getX();

  /**
   * @return renvoie la position Y
   */
  float getY();

  /**
   * @return renvoie une position 
   */
  positions getPos();
};

#endif