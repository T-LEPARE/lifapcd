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

void Position::setX(float x){
  this->xy.x = x ;
}

void Position::setY(float y){
  this->xy.y = y ;
}

void Position::setPos(float x,float y){
  setX(x);
  setY(y);
}