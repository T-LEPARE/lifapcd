#include "Invaders.h"

    Invader::Invader()
    {
        pos=Position(100,100);
        direction=Position(0,-1);
        HP=10;
        speed=2.0f;
        dmg=1;
        height=25;
        width=50;
    }

    Invader::Invader(float x,float y)
    {
        pos=Position(x,y);
        direction=Position(0,-1);
        HP=10;
        speed=2.0f;
        dmg=1;
        height=50;
        width=100;
    }

    Invader::~Invader()
    {
    
    }

    Invader Invader::InitInvader(float x, float y, int HealthPoint,float spd,int damage)
    {
        pos=Position(x,y);
        HP=HealthPoint;         
        dmg=damage;
        speed=spd;
        return *this;
    }

    void Invader::setPos(float x,float y)
    {
        pos.x=x;
        pos.y=y;
    }

    void Invader::setHP(int HealthPoint)
    {
        HP=HealthPoint;
    }

    void Invader::setSpeed(float spd)
    {
        speed=spd;
    }

    void Invader::setDamage(int damage)
    {
        dmg=damage;
    }

    Position Invader::getPos()
    {
        return pos;
    }

    int Invader::getDamage(){
        return dmg;
    }

    float Invader::getSpeed()
    {
        return speed;
    }

    int Invader::getHP()
    {
        return HP;
    }

    Position Invader::getDirection()
    {
        return direction;
    }

    void Invader::setDirection(float x,float y)
    {
        direction = Position(x,y);
    }
    
    void Invader::setDirection(Position p)
    {
        direction = p;
    }
        
    float Invader::getWidth()
    {
        return this->width;
    }

    float Invader::getHeight()
    {
        return this->height;
    }

    void Invader::movement()
    {
        //pattern à modifier plus tard
        if (pos.x >=900)//Display::getDIMW()
            speed*-1.;
        if (pos.x <=0)
            speed*-1;
        pos.x+=speed;
    }

    bool Invader::CheckCollision(Projectile P){
        Position position = P.getPos();
        if (position.x >= pos.x && position.x <= pos.x+width && position.y >= pos.y && position.y <= pos.y+width)
            return true;
        return false;
    }

    void Invader::DamageTaken(bool b, Weapon w)
    {
        int dmg=w.getDamage();
        if (b)
            HP-=dmg;
    }


        SDL_Texture* Invader::getTexture(){
            return texture;
        }
        SDL_Surface* Invader::getSurface(){
            return surface;
        }
        void Invader::setTexture(SDL_Texture* _texture){
            texture = _texture;
        }
        void Invader::setSurface(SDL_Surface* _surface){
            surface = _surface;
    }