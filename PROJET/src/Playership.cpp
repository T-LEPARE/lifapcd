#include "Playership.h"

    Player::Player()
    {
        pos=Position(0,0);
        HP=100;
    }

    Player::Player(float x, float y, int healthPoint, float playerSpeed) { 
        this->setPos(x, y);
        this->setHP(healthPoint); 
        this->setSpeed(playerSpeed);
    }

    Player::~Player()
    {
        Player();
    }

    Player Player::InitPlayer(float x, float y, int healthPoint)
    {
        //pos=Position(x,y);
        //HP=HealthPoint;   
        return Player(x, y, healthPoint, speed);      
    }

    void Player::setPos(float x,float y){
    this->pos.x=x;
    this->pos.y=y;
}

    Position Player::getPos()
    {
        return pos;
    }

    void Player::setHP(int healthPoint){
    this->HP = healthPoint;
}
    int Player::getHP()
    {
        return HP;
    }
    void Player::setSpeed(float speed)
    {
        this->speed = speed;
    }
        float Player::getSpeed()
    {
        return this->speed;
    }

    void Player::movement()
    {
        SDL_Event event; 
        int SDL_EnableKeyRepeat(100);
        while( SDL_PollEvent(&event) ){
            switch( event.key.keysym.sym ){
            case SDLK_DOWN:
                pos.y+=speed;
                break;

            case SDLK_UP:
                pos.y-=speed;
                break;

            case SDLK_RIGHT:
                pos.x+=speed;
                break;

            case SDLK_LEFT:
                pos.x-=speed;
                break;
            default:
                break;
    }
  }
    }

    bool Player::CheckCollisionP(Projectile P){
        Position position = P.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTaken(bool b,Projectile P)
    {
        int dmg=P.getDamage();
        if (b)
            HP-=dmg;
    }

    bool Player::CheckCollisionI(Invader i){
        Position position = i.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTaken(bool b,Invader i)
    {
        int dmg=i.getDamage();
        if (b)
            HP-=dmg;
    }

