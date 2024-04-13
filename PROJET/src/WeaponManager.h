#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <map>
#include <string>

class WeaponManager {
public:
  /**
   * @brief Default constructor for WeaponManager. Initializes a map containing weapon data.
   */
  WeaponManager();

  /**
   * @brief Destructor for WeaponManager.
   */
  ~WeaponManager();

  /**
   * @brief Structure representing a weapon type with its properties.
   */
  struct weaponType {
    /**
     * @brief Speed of the weapon's projectile.
     */
    float projectileSpeed;
    /**
     * @brief Damage dealt by the weapon's projectile.
     */
    int damage;
    /**
     * @brief Fire rate of the weapon (projectiles per second).
     */
    float fireRate;
    /**
     * @brief Width of the weapon's projectile.
     */
    int projectileWidth;
    /**
     * @brief Height of the weapon's projectile.
     */
    int projectileHeight;
  };

  /**
   * @brief Gets a map containing all available weapons and their properties.
   * @return A map where keys are weapon names and values are weaponType structures.
   */
  std::map<std::string, weaponType> getWeapons() const;

  /**
   * @brief Gets the damage of a specific weapon.
   * @param weaponName The name of the weapon.
   * @return The damage dealt by the weapon's projectile.
   */
  int getDamage(const std::string& weaponName) const;

  /**
   * @brief Gets the projectile speed of a specific weapon.
   * @param weaponName The name of the weapon.
   * @return The speed of the weapon's projectile.
   */
  float getProjectileSpeed(const std::string& weaponName) const;

  /**
   * @brief Gets the fire rate of a specific weapon.
   * @param weaponName The name of the weapon.
   * @return The fire rate of the weapon (projectiles per second).
   */
  float getfireRate(const std::string& weaponName) const;

  /**
   * @brief Gets the projectile width of a specific weapon.
   * @param weaponName The name of the weapon.
   * @return The width of the weapon's projectile.
   */
  float getProjectileWidth(const std::string& weaponName) const;

  /**
   * @brief Gets the projectile height of a specific weapon.
   * @param weaponName The name of the weapon.
   * @return The height of the weapon's projectile.
   */
  float getProjectileHeight(const std::string& weaponName) const;

  /**
   * @brief Gets the name of the next weapon in the internal weapon list (circular).
   * @param weaponName The current weapon name.
   * @return The name of the next weapon, or the first weapon's name if at the end.
   */
  std::string getnextWeaponName(const std::string& weaponName);

private:
  std::map<std::string, weaponType> weaponTypes;  // Map containing weapon data
};

#endif