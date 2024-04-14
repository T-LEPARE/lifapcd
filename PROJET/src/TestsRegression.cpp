#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "Playership.h"
#include "Position.h"
#include "Projectile.h"
#include "InvadersManager.h"
#include "StarblitzGameDisplay.h"
#include "ProjectileManager.h"
#include "WeaponManager.h"
#include "Weapon.h"
#include "ScoreSystem.h"
#include <memory>
#include <gtest/gtest.h>



TEST(PlayerTest, PlayerConstructors) {

  Player player1;
  EXPECT_EQ(player1.getHP(), 100);
  EXPECT_EQ(player1.getSpeed(), 6.0f);
  EXPECT_EQ(player1.getWidth(), 100);
  EXPECT_EQ(player1.getHeight(), 75);
  EXPECT_EQ(player1.getPos().x, 270.0f - player1.getWidth() / 2.0f);
  EXPECT_EQ(player1.getPos().y, 960.0f - player1.getHeight() * 1.25f);


  Player player2(150, 200, 50, 8.0f, 50, 70, Position(1.0f, -1.0f));
  EXPECT_EQ(player2.getHP(), 150);
  EXPECT_EQ(player2.getSpeed(), 8.0f);
  EXPECT_EQ(player2.getWidth(), 70);
  EXPECT_EQ(player2.getHeight(), 50);
  EXPECT_EQ(player2.getPos().x, 150.0f);
  EXPECT_EQ(player2.getPos().y, 200.0f);
  EXPECT_EQ(player2.getDir().x, 1.0f);
  EXPECT_EQ(player2.getDir().y, -1.0f);
}

TEST(PlayerTest, PlayerSetters) {
  Player player;

  player.setHP(200);
  EXPECT_EQ(player.getHP(), 200);

  player.setSpeed(10.0f);
  EXPECT_EQ(player.getSpeed(), 10.0f);

  player.setWidth(80);
  EXPECT_EQ(player.getWidth(), 80);

  player.setHeight(60);
  EXPECT_EQ(player.getHeight(), 60);

  player.setPos(300.0f, 400.0f);
  EXPECT_EQ(player.getPos().x, 300.0f);
  EXPECT_EQ(player.getPos().y, 400.0f);

  player.setDir(Position(0.5f, 0.2f));
  EXPECT_EQ(player.getDir().x, 0.5f);
  EXPECT_EQ(player.getDir().y, 0.2f);
}

TEST(PlayerTest, PlayerMovement) {
  Player player;
  player.setPos(100.0f, 100.0f);
  player.setSpeed(5.0f);
  player.setWidth(50);
  player.setHeight(30);


  Uint8 mockKeyboardState[256] = {0};
  mockKeyboardState[SDL_SCANCODE_RIGHT] = 1;


  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 105.0f); 
  EXPECT_EQ(player.getPos().y, 100.0f);
  EXPECT_EQ(player.getDir().x, 1.0f); 


  player.setPos(540.0f - player.getWidth(), 100.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 540.0f - player.getWidth());
  EXPECT_EQ(player.getPos().y, 100.0f);


  mockKeyboardState[SDL_SCANCODE_RIGHT] = 0;
  mockKeyboardState[SDL_SCANCODE_LEFT] = 1;
  player.setPos(150.0f, 100.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 145.0f); 
  EXPECT_EQ(player.getPos().y, 100.0f);
  EXPECT_EQ(player.getDir().x, -1.0f); 

  
  player.setPos(0.0f, 100.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 0.0f);
  EXPECT_EQ(player.getPos().y, 100.0f);


  mockKeyboardState[SDL_SCANCODE_LEFT] = 0;
  mockKeyboardState[SDL_SCANCODE_UP] = 1;
  mockKeyboardState[SDL_SCANCODE_DOWN] = 1;
  player.setPos(200.0f, 200.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 200.0f);
  EXPECT_EQ(player.getPos().y, 200.0f);


  mockKeyboardState[SDL_SCANCODE_DOWN] = 0;
  player.setPos(200.0f, 500.0f - player.getHeight());
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 200.0f);
  EXPECT_EQ(player.getPos().y, 495.0f); 


  player.setPos(200.0f, 0.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 200.0f);
  EXPECT_EQ(player.getPos().y, 0.0f);


  player.setPos(200.0f, 100.0f);
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 200.0f);
  EXPECT_EQ(player.getPos().y, 105.0f); 


  player.setPos(200.0f, 960.0f - player.getHeight());
  player.moveShip(mockKeyboardState);
  EXPECT_EQ(player.getPos().x, 200.0f);
  EXPECT_EQ(player.getPos().y, 960.0f - player.getHeight());
}

TEST(ProjectileManagerTest, Constructors) {
  ProjectileManager manager;
  EXPECT_EQ(manager.getProjectiles().size(), 0);
}

TEST(ProjectileManagerTest, AddAndRemoveProjectiles) {
  ProjectileManager manager;


  std::unique_ptr<Projectile> projectile(new Projectile);
  manager.addProjectile(std::move(projectile));
  EXPECT_EQ(manager.getProjectiles().size(), 1);


  std::unique_ptr<Projectile> projectile2(new Projectile);
  manager.addProjectile(std::move(projectile2));
  EXPECT_EQ(manager.getProjectiles().size(), 2);


  manager.removeProjectiles(projectile);
  EXPECT_EQ(manager.getProjectiles().size(), 1);


  manager.removeProjectiles(projectile);
  EXPECT_EQ(manager.getProjectiles().size(), 1);
}

TEST(ProjectileManagerTest, IsProjectileOutOfBounds) {
  ProjectileManager manager;


  Projectile projectile;
  projectile.setPos(100.0f, 100.0f);


  EXPECT_FALSE(manager.isProjectileOutOfBounds(std::make_unique<Projectile>(projectile)));


  projectile.setPos(-10.0f, 100.0f);
  EXPECT_TRUE(manager.isProjectileOutOfBounds(std::make_unique<Projectile>(projectile)));


  projectile.setPos(Display::getDIMW() + 10.0f, 100.0f);
  EXPECT_TRUE(manager.isProjectileOutOfBounds(std::make_unique<Projectile>(projectile)));


  projectile.setPos(100.0f, -10.0f);
  EXPECT_TRUE(manager.isProjectileOutOfBounds(std::make_unique<Projectile>(projectile)));


  projectile.setPos(100.0f, Display::getDIMH() + 10.0f); 
  EXPECT_TRUE(manager.isProjectileOutOfBounds(std::make_unique<Projectile>(projectile)));
}

TEST(WeaponTest, Constructor_ValidWeapon) {
  WeaponManager weaponManager;
  Weapon weapon("mitraillette", weaponManager);
  EXPECT_EQ(weapon.getName(), "mitraillette");
}

TEST(WeaponTest, Constructor_InvalidWeapon) {
  WeaponManager weaponManager;
  Weapon weapon("blaster", weaponManager);
  EXPECT_EQ(weapon.getName(), "");
}

TEST(WeaponManagerTest, Getters) {
  WeaponManager weaponManager;


  EXPECT_EQ(weaponManager.getDamage("mitraillette"), 1);
  EXPECT_EQ(weaponManager.getDamage("railgun"), 10);
  EXPECT_EQ(weaponManager.getDamage("roquettes"), 5);


  EXPECT_EQ(weaponManager.getProjectileSpeed("mitraillette"), 9.0f);
  EXPECT_EQ(weaponManager.getProjectileSpeed("railgun"), 8.0f);
  EXPECT_EQ(weaponManager.getProjectileSpeed("roquettes"), 7.0f);


  EXPECT_EQ(weaponManager.getfireRate("mitraillette"), 100.0f);
  EXPECT_EQ(weaponManager.getfireRate("railgun"), 1000.0f);
  EXPECT_EQ(weaponManager.getfireRate("roquettes"), 750.0f);


  EXPECT_EQ(weaponManager.getProjectileWidth("mitraillette"), 1.0f);
  EXPECT_EQ(weaponManager.getProjectileWidth("railgun"), 5.0f);
  EXPECT_EQ(weaponManager.getProjectileWidth("roquettes"), 20.0f);


  EXPECT_EQ(weaponManager.getProjectileHeight("mitraillette"), 5.0f);
  EXPECT_EQ(weaponManager.getProjectileHeight("railgun"), 100.0f);
  EXPECT_EQ(weaponManager.getProjectileHeight("roquettes"), 30.0f);
}

TEST(WeaponManagerTest, GetNextWeaponName_Valid) {
  WeaponManager weaponManager;

  EXPECT_EQ(weaponManager.getnextWeaponName("mitraillette"), "railgun");
  EXPECT_EQ(weaponManager.getnextWeaponName("railgun"), "roquettes");
  EXPECT_EQ(weaponManager.getnextWeaponName("roquettes"), "mitraillette");
}

TEST(WeaponManagerTest, GetNextWeaponName_Invalid) {
  WeaponManager weaponManager;
  EXPECT_DEATH(weaponManager.getnextWeaponName("blaster"), ""); 
}
