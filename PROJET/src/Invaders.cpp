#include "Invaders.h"
#include "StarblitzGameDisplay.h"


    Invader::Invader()
    {
        pos=Position(0,0);
        HP=10;
        speed=2.0;
        dmg=1;
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
    }

    void Invader::setPos(float x,float y)
    {
    this->pos.x=x;
    this->pos.y=y;
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


    int Invader::getHP()
    {
        return HP;
    }

    void Invader::movement()
    {
        //pattern à modifier plus tard
        if (this->pos.x >=DIMW)
            speed*-1.;
        if (this->pos.x <=0)
            speed*-1;
        this->pos.x+=speed;
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


