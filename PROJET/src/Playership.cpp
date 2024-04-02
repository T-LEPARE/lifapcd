#include "Playership.h"



    Player::Player()
    {
        HP=100;
        speed=7;
        height=50;
        width=100;
        pos=Position(270-width/2,960-height*1.25);
        direction = Position(0,0);
        changeWeapon("mitraillette");
    }

    Player::Player(float x, float y, int healthPoint, float playerSpeed, float height, float width, Position direct) { 
        this->setPos(x, y);
        this->setHP(healthPoint); 
        this->setSpeed(playerSpeed);
        this->setHeight(height);
        this->setWidth(width);
        this->setDir(direct);
    }

    Player::~Player()
    {
        Player();
    }

    Player Player::InitPlayer(float x, float y, int healthPoint,float spd,float height, float width, Position direct)
    {   
        return Player(x, y, healthPoint, spd, height, width, direct);
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
    void Player::setWidth(int w)
    {
        this->width=w;
    }
    void Player::setHeight(int h)
    {
        this->height=h;
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

    SDL_Texture* Player::getTexture(){
        return texture;
    }
    SDL_Surface* Player::getSurface(){
        return surface;
    }
    void Player::setTexture(SDL_Texture* _texture){
        texture = _texture;
    }
    void Player::setSurface(SDL_Surface* _surface){
        surface = _surface;
    }


    Position Player::getDir()
    {
        return direction;
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

    float Player::getWidth()
    {
        return this->width;
    }

    float Player::getHeight()
    {
        return this->height;
    }

    void Player::movement(SDL_Event &event)
    {
        int keypressed;
        switch( event.type ){
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_s:
                    setDirY(1);
                    keypressed++;
                    break;

                case SDLK_UP:
                case SDLK_z:
                case SDLK_w:
                    setDirY(-1);
                    keypressed++;
                    break;

                case SDLK_RIGHT:
                case SDLK_d:
                    setDirX(1);
                    keypressed++;
                    break;

                case SDLK_LEFT:
                case SDLK_q:
                case SDLK_a:
                    setDirX(-1);
                    keypressed++;
                    break;
                default:
                    break;
            }
            break;

            case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_s:
                    setDirY(0);
                    keypressed--;
                    break;

                case SDLK_UP:
                case SDLK_z:
                case SDLK_w:
                    setDirY(0);
                    keypressed--;
                    break;

                case SDLK_RIGHT:
                case SDLK_d:
                    setDirX(0);
                    keypressed--;
                    break;

                case SDLK_LEFT:
                case SDLK_q:
                case SDLK_a:
                    setDirX(0);
                    keypressed--;
                    break;
                default:
                    break;
            }
            break;
        }
        if (keypressed>=2){
            pos.x += direction.x * speed/2 ;
            pos.y += direction.y * speed/2 ;
        }
        else{
            pos.x += direction.x * speed ;
            pos.y += direction.y * speed ; 
        }
}

    // Pourquoi on a ça alors qu'on a DamageTakenInvader ?
    void Player::DamageTakenProjectile(bool b,Projectile P)
    {
        int dmg=P.getDamage();
        if (b)
            HP-=dmg;
    }


    void Player::DamageTakenInvader(bool b,Invader I)
    {
        int dmg=I.getDamage();
        if (b)
            HP-=dmg;
    }

    // void Player::shoot() {
    //     currentWeapon.fire(pos, direction);
    // }

    void Player::setCurrentWeapon(Weapon::weaponType weapon) {
        currentWeapon = weapon;
    }

    void Player::changeWeapon(const std::string& weaponName) {
    // Retrieve weapon data
    Weapon weapon;
    std::map<std::string, Weapon::weaponType> weaponList = weapon.getWeapons();
    Weapon::weaponType newWeapon = weaponList.at(weaponName);
    setCurrentWeapon(newWeapon);
    }

    std::string Player::getCurrentWeaponName() {
        return currentWeaponName;
    }

    bool Player::CollisionWindow(){
        if (pos.x <=0) {
            setPos(0,pos.y);
        }
        if (pos.x+width >=540) {
            setPos(540-width,pos.y);
        }
        if (pos.y+height>=960) {
            setPos(pos.x,960-height);
        }      
        if (pos.y <=0) {
            setPos(pos.x,0);    
        }
    }
