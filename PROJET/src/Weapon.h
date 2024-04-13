#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <map>
#include "WeaponManager.h"

class Player;
class ProjectileManager;

class Weapon {
public:
  /**
   * @brief Default constructor for Weapon.
   */
  Weapon();

  /**
   * @brief Constructor for Weapon. Initializes a weapon with a specific name and reference to a WeaponManager.
   * @param weaponName The name of the weapon.
   * @param weaponManager Reference to a WeaponManager object.
   */
  Weapon(std::string weaponName, WeaponManager& weaponManager);

  /**
   * @brief Destructor for Weapon.
   */
  ~Weapon();

  /**
   * @brief Gets the weapon's name.
   * @return The weapon's name as a string.
   */
  std::string getName();


private:
  std::string name;  // Weapon name
  WeaponManager::weaponType weapon;  // Weapon type (obtained from WeaponManager)
};

#endif