#include "Position.h"

Position operator+ (Position a, Position b) {
  Position newPos;
  newPos.x = a.x + b.x;
  newPos.y = a.y + b.y;
  return newPos;
}

Position operator* (float a, Position b){
  Position newPos;
  newPos.x = a * b.x;
  newPos.y = a * b.y;
  return newPos;
}

Position operator* (Position b, float a){
  Position newPos;
  newPos.x = a * b.x;
  newPos.y = a * b.y;
  return newPos;
}

Position::Position(float _x, float _y) : x(_x), y(_y) {}

Position::Position(){
  x=y=0;
}