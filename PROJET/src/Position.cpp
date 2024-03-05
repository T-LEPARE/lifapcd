#include "Position.h"

Position::Position(){
}

Position::Position (float x, float y) {
  this->xy.x = x;
  this->xy.y = y;
}

float Position::getX() {
  return xy.x;
}

float Position::getY() {
  return xy.y;
}

positions Position::getPos(){
  return xy;
}