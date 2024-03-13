#include "Invaders.h"

    Invader::Invader()
    {
        pos=Position(0,0);
        direction=Position(0,-1);
        HP=10;
        speed=2.0f;
        dmg=1;
        taille=32.0f;
    }

    Invader::~Invader()
    {
        Invader();
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
    void Invader::setTaille(float TailleInvader)
    {
        taille=TailleInvader;
    }


    float Invader::getTaille()
    {
        return taille;
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

    void Invader::movement()
    {
        //pattern à modifier plus tard
        if (pos.x >=Display::getDIMW())
            speed*-1.;
        if (pos.x <=0)
            speed*-1;
        pos.x+=speed;
    }

    bool Invader::CheckCollision(Projectile P){
        Position position = P.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Invader::DamageTaken(bool b, Projectile P)
    {
        int dmg=P.getDamage();
        if (b)
            HP-=dmg;
    }


