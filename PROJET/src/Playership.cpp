#include "Playership.h"


    Player::Player()
    {
        pos=Position(0,0);
        HP=100;
        speed=2.0;
        taille=10;
    }

    Player::Player(float x, float y, int healthPoint, float playerSpeed, float TaillePlayer) { 
        this->setPos(x, y);
        this->setHP(healthPoint); 
        this->setSpeed(playerSpeed);
        this->setTaille(TaillePlayer);
    }

    Player::~Player()
    {
        Player();
    }

    Player Player::InitPlayer(float x, float y, int healthPoint,float spd,float TaillePlayer)
    {   
        return Player(x, y, healthPoint, spd, TaillePlayer);      
    }

    void Player::setPos(float x,float y){
    this->pos.x=x;
    this->pos.y=y;
    }

    void Player::setHP(int healthPoint){
    this->HP = healthPoint;
    }

    void Player::setSpeed(float speed)
    {
        this->speed = speed;
    }
    void Player::setTaille(int t)
    {
        this->taille=t;
    }

    int Player::getHP()
    {
        return HP;
    }

    float Player::getSpeed()
    {
        return this->speed;
    }

    Position Player::getPos()
    {
        return this->pos;
    }

    float Player::getTaille()
    {
        return this->taille;
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

    bool Player::CheckCollisionP(Projectile Projectile){
        Position position = Projectile.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTakenP(bool b,Projectile Projectile)
    {
        int dmg=Projectile.getDamage();
        if (b)
            HP-=dmg;
    }

    bool Player::CheckCollisionI(Invader Invader){
        Position position = Invader.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTakenI(bool b,Invader Invader)
    {
        int dmg=Invader.getDamage();
        if (b)
            HP-=dmg;
    }

