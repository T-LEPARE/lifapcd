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
        //SDL2 pour le mvt
    }

    bool Player::CheckCollision(Projectile P){
        Position position = P.getpos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

        void Player::DamageTaken(bool b, Projectile P)
    {
        int dmg=P.getDamage();
        if (b)
            HP-=dmg;
    }
};

