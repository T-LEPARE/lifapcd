#include "Invaders.h"

    Invader::Invader()
    {
        pos=Position(100,100);
        direction=Position(1,0);
        HP=10;
        speed=2.0f;
        dmg=1;
        height=30;
        width=50;
    }

    Invader::Invader(float x,float y,float NvHP, int Nvdmg)
    {
        pos=Position(x,y);
        direction=Position(1,0);
        HP=NvHP;
        speed=2.0f;
        dmg=Nvdmg;
        height=30;
        width=50;
    }

    Invader::~Invader()
    {
        //InvadersManager devrait s'occuper de tout
    }

    Invader Invader::InitInvader(float x, float y, int HealthPoint,float spd,int damage)
    {
        pos=Position(x,y);
        HP=HealthPoint;         
        dmg=damage;
        speed=spd;
        return *this;
    }

    void Invader::setPos(float x,float y)
    {
        pos.x=x;
        pos.y=y;
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

    float Invader::getSpeed()
    {
        return speed;
    }

    int Invader::getHP()
    {
        return HP;
    }

    Position Invader::getDirection()
    {
        return direction;
    }

    void Invader::setDirection(float x,float y)
    {
        direction = Position(x,y);
    }
    
    void Invader::setDirection(Position p)
    {
        direction = p;
    }
        
    float Invader::getWidth()
    {
        return this->width;
    }

    float Invader::getHeight()
    {
        return this->height;
    }

    SDL_Texture* Invader::getTexture(){
        return texture;
    }
    SDL_Surface* Invader::getSurface(){
        return surface;
    }
    void Invader::setTexture(SDL_Texture* _texture){
        texture = _texture;
    }
    void Invader::setSurface(SDL_Surface* _surface){
        surface = _surface;
    }
    

    void Invader::shootInvader(ProjectileManager& projectileManager) {
        Uint32 maintenant = SDL_GetTicks();
        if (maintenant - dernier_tir > 2000) 
        {
            dernier_tir = maintenant;
            std::unique_ptr<Projectile> p = std::make_unique<Projectile>(
            Position(Invader::getPos().x+Invader::getWidth()/2,
            Invader::getPos().y+(Invader::getHeight()+30)),
            Invader::getDamage());
            projectileManager.addProjectile(std::move(p));
        }
    }

    bool Invader::ArriveEnBas()
    {
        if (pos.y+height>960)
            return true;
        return false;
    }

    bool Invader::HPnullInvader()
    {
        if(HP <= 0)
            return true;
        return false;
    }
