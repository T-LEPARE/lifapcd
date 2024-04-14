#include "Playership.h"
#include "ProjectileManager.h"
#include <iostream>
#include <string>

    Player::Player()
    {   WeaponManager weaponManager;
        HP=100;
        speed=6;
        height=75;
        width=100;
        pos=Position(270-width/2,960-height*1.25);
        direction = Position(0,0);
        currentWeaponName = "mitraillette";
        currentWeapon = Weapon(currentWeaponName,weaponManager);

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

    Weapon Player::getCurrentWeapon() {
        return this->currentWeapon;
    }

void Player::moveShip(const Uint8 *keyboardState) {
  // Vérifie l'état des touches de déplacement (flèches)
  int intendedX = pos.x + (keyboardState[SDL_SCANCODE_RIGHT] ? 1 : 0) * speed;
  int intendedY = pos.y + (keyboardState[SDL_SCANCODE_DOWN] ? 1 : 0) * speed;
  intendedX -= (keyboardState[SDL_SCANCODE_LEFT] ? 1 : 0) * speed;
  intendedY -= (keyboardState[SDL_SCANCODE_UP] ? 1 : 0) * speed;

  // Calculate valid movement within bounds
  int actualX = std::min(std::max(intendedX, 0), 540 - width);
  int actualY = std::min(std::max(intendedY, 0), 960 - height);

  // Update position and direction based on actual movement
  pos.x = actualX;
  pos.y = actualY;

  if (intendedX != actualX) {
    if (intendedX > pos.x) {
        setDirX(1);
    }
    else{
        setDirX(-1);
    }
  }
  if (intendedY != actualY) {
    if (intendedY > pos.y) {
        setDirY(1);
    }
    else{
        setDirY(-1);
    }
  }
}

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

    void Player::setCurrentWeapon(Weapon weapon) {
        currentWeapon = weapon;
    }

    bool Player::TempsPourChanger() {
    Uint32 maintenant = SDL_GetTicks();
    if (maintenant - dernier_changement > 150)
        return true;
    return false;
    }

    void Player::changeWeapon(WeaponManager& weaponManager,const Uint8 *keyboardState) {
        Uint32 maintenant = SDL_GetTicks();
        if (TempsPourChanger()) 
        {
            dernier_changement = maintenant;
            if(keyboardState[SDL_SCANCODE_D]){
            std::cout << "currentWeaponName : " << getCurrentWeaponName() << std::endl;
            std::string nextWeaponName = weaponManager.getnextWeaponName(currentWeaponName);
            std::cout << "nextWeaponName : " << nextWeaponName << std::endl;
            Weapon nextWeapon = Weapon(nextWeaponName,weaponManager);
            currentWeaponName = nextWeaponName;
            currentWeapon = nextWeapon;}
        }
    }

    std::string Player::getCurrentWeaponName() {
        return currentWeaponName;
    }


    void Player::CollisionWindow(){
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


    bool Player::peutTirer() {
    Uint32 maintenant = SDL_GetTicks();
    WeaponManager wp;
    if (maintenant - dernier_tir > wp.getfireRate(getCurrentWeaponName()))
        return true;
    return false;
    }

    void Player::firePlayer(ProjectileManager& projectileManager, WeaponManager& weaponManager,const Uint8 *keyboardState,SDL_AudioDeviceID audioDevice, Uint8* wavBuffer, Uint32 wavLength) {
        Uint32 maintenant = SDL_GetTicks();
        if (peutTirer()) {
            dernier_tir = maintenant;
            float x,y;
            if (getCurrentWeaponName()=="mitraillette")
            {
                 x =Player::getPos().x+Player::getWidth()/2;
                 y =Player::getPos().y+2;
                 SDL_QueueAudio(audioDevice, wavBuffer, wavLength);
                 SDL_PauseAudioDevice(audioDevice, 0);
            }
            if (getCurrentWeaponName()=="railgun")
            {
                 x =Player::getPos().x+Player::getWidth()/2-2.5;
                 y =Player::getPos().y-100;
            }
            if (getCurrentWeaponName()=="roquettes")
            {
                 x =Player::getPos().x+Player::getWidth()/2-10;
                 y =Player::getPos().y-30;
            }
            if (keyboardState[SDL_SCANCODE_SPACE]) {
                std::string currentWeaponName = getCurrentWeaponName();
                std::unique_ptr<Projectile> p = std::make_unique<Projectile>(
                    x,y,
                    currentWeaponName,
                    weaponManager
                );
                projectileManager.addProjectile(std::move(p));
            }
        }
}



    bool Player::HPnullPlayership()
    {
        if(HP <= 0)
            return true;
        return false;
    }

    void Player::playerDeath(ProjectileManager& projectileManager){
        if (HPnullPlayership()){
            projectileManager.clearTab();
            HP=100;
            speed=7;
            pos=Position(270-width/2,960-height*1.25);
            direction = Position(0,0);
        }
    }
