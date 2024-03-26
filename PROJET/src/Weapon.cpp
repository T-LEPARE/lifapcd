#include "Weapon.h"

struct weapon {
    float projectileSpeed;
    int damage;
    float fireRate;
};

std::map<std::string, weapon> Weapon::getWeapons() {
    return weaponTypes;
}