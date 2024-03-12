#ifndef POSITION_H
#define POSITION_H

struct Position
{
  float x;
  float y;

  Position(float _x, float _y);
  Position();
};

  Position operator+ (Position, Position);
  Position operator* (float, Position);
  Position operator* (Position, float);

#endif