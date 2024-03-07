#include "Position.h"

/*
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
*/

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