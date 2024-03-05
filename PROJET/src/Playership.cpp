#include <SDL2/SDL.h>
#include <Playership.h>

class Player {
private:
    Position pos;
    float speed;
    float taille;
    float HP;
public:
    Player::Player()
    {
        pos=Position();
        HP=10;
    }

    ~Player(){}

    Player Player::InitPlayer(float x, float y, int HealthPoint)
    {
        pos=Position(x,y);
        HP=HealthPoint;         
    }

    Position Player::getPos()
    {
        return pos;
    }

    int Player::getHP()
    {
        return HP;
    }

    void Player::movement()
    {
        if (evenement.type == SDL_KEYDOWN)
        {
            pos.y+=speed;
        }
        if (evenement.type == SDL_KEYUP)
        {
            pos.y-=speed;
        }
        if (evenement.type == SDL_KEYLEFT)
        {
            pos.x-=speed;
        }
        if (evenement.type == SDL_KEYRIGHT)
        {
            pos.x+=speed;
        }
    }

    bool Invader::CheckCollision(Projectile P){
        Position position =P.getpos();
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

