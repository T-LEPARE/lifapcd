#include "Playership.h"



    Player::Player()
    {
        pos=Position(0,0);
        HP=100;
        speed=1.0;
        taille=10;
        direction = Position(0,-1);
    }

    Player::Player(float x, float y, int healthPoint, float playerSpeed, float TaillePlayer, Position direct) { 
        this->setPos(x, y);
        this->setHP(healthPoint); 
        this->setSpeed(playerSpeed);
        this->setTaille(TaillePlayer);
        this->setDir(direct);
    }

    Player::~Player()
    {
        Player();
    }

    Player Player::InitPlayer(float x, float y, int healthPoint,float spd,float TaillePlayer, Position direct)
    {   
        return Player(x, y, healthPoint, spd, TaillePlayer, direct);
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
    void Player::setDirX(float x){
    this->direction.x=x;
    }

    void Player::setDirY(float y){
    this->direction.y=y;
    }
    void Player::setDir(Position p){
    this->direction.x=p.x;
    this->direction.y=p.y;
}


    Position Player::getDir()
    {
    return pos;
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
            case SDLK_s:
                setDirY(1);//On modifie le vecteur direction
                pos.y+=direction.y*speed; //Mise à jour de la position du joueur
                break;

            case SDLK_UP:
            case SDLK_z:
            case SDLK_w: //pour le QWERTY
                setDirY(-1);
                pos.y+=direction.y*speed;
                break;

            case SDLK_RIGHT:
            case SDLK_d:
                setDirX(1);
                pos.x+=direction.x*speed;
                break;

            case SDLK_LEFT:
            case SDLK_q:
            case SDLK_a: //pour le QWERTY
                setDirX(-1);
                pos.x+=direction.x*speed;
                break;
            default:
                break;
             }   
        }
        //Remise à 0 du vecteur direction du joueur
        setDirX(0);
        setDirY(0);
    }

    bool Player::CheckCollisionProjectile(Projectile Projectile){
        Position position = Projectile.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTakenProjectile(bool b,Projectile Projectile)
    {
        int dmg=Projectile.getDamage();
        if (b)
            HP-=dmg;
    }

    bool Player::CheckCollisionInvader(Invader Invader){
        Position position = Invader.getPos();
        if (position.x >= pos.x && position.x <= pos.x+taille && position.y >= pos.y && position.y <= pos.y+taille)
            return true;
        return false;
    }

    void Player::DamageTakenInvader(bool b,Invader Invader)
    {
        int dmg=Invader.getDamage();
        if (b)
            HP-=dmg;
    }

