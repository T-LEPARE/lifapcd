#include <Invaders.h>
#include <Starblitzgame.h>

class Invader {
private:
    Position pos;
    float speed;
    float taille;
    float HP;
public:
    Invader::Invader()
    {
        pos=Position(0,0);
        HP=10;
    }

    ~Invader()
    {
        Invader();
    }

    Invader Invader::InitInvader(float x, float y, int HealthPoint)
    {
        pos=Position(x,y);
        HP=HealthPoint;         
    }

    void Invader::setPos(float x,float y)
    {
    this->pos.x=x;
    this->pos.y=y;
    }

    Position Invader::getPos()
    {
        return pos;
    }

    int Invader::getHP()
    {
        return HP;
    }

    void Invader::movement()
    {
        //pattern
        float a;
        if (pos.x >=DIMX)
            a=-1.;
        if (pos.x <=0)
            a=1.;
        pos.x+=a;
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
};

