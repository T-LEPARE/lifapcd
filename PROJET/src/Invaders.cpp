#include <Invaders.h>

class Invader {
private:
    Position pos;
    float speed;
    float taille;
    float HP;
public:
    Invader::Invader()
    {
        pos=Position();
        HP=10;
    }

    ~Invader(){}

    Invader Invader::InitInvader(float x, float y, int HealthPoint)
    {
        pos=Position(x,y);
        HP=HealthPoint;         
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
    }

    bool Invader::CheckCollision(Projectile P){
        Position position = P.pos.getPos();
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

