#ifndef WEAPON_H
#define WEAPON_H
#include <map>
#include <string>

class Weapon {

private:

struct weapon {
    float projectileSpeed;
    int damage;
    float fireRate;
};
const std::map<std::string, weapon> weaponTypes = {
    // {nom,{projectile speed projectile,damage, fire rate}}
    {"mitraillette",{2, 1, 50}},
    {"railgun", {50, 50, 1}},
    {"roquettes", {20, 25, 2}},
};


public:
std::map<std::string, weapon> getWeapons();

};

#endif 