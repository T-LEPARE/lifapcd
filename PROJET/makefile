all : ./bin/StarblitzGame


./bin/StarblitzGame : ./obj/StarblitzGameDisplay.o  ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o ./obj/Partie.o ./obj/InvadersManager.o ./obj/Weapon.o ./obj/ProjectileManager.o ./obj/WeaponManager.o
			g++ -Wall -g ./obj/StarblitzGameDisplay.o ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o ./obj/Partie.o ./obj/InvadersManager.o ./obj/Weapon.o ./obj/ProjectileManager.o ./obj/WeaponManager.o -o ./bin/StarblitzGame -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


./obj/Partie.o : ./src/Partie.cpp ./src/Playership.h ./src/Position.h ./src/Projectile.h ./src/Invaders.h ./src/StarblitzGameDisplay.h
			g++ -Wall -c ./src/Partie.cpp -o ./obj/Partie.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


./obj/StarblitzGameDisplay.o : ./src/StarblitzGameDisplay.cpp ./src/StarblitzGameDisplay.h ./src/Playership.h ./src/Projectile.h ./src/Weapon.h ./src/ProjectileManager.h
			g++ -Wall -c ./src/StarblitzGameDisplay.cpp -o ./obj/StarblitzGameDisplay.o -lSDL2 -lSDL2_image


./obj/ScoreSystem.o : ./src/ScoreSystem.cpp ./src/ScoreSystem.h
			g++ -Wall -c ./src/ScoreSystem.cpp -o ./obj/ScoreSystem.o


./obj/Projectile.o : ./src/Projectile.cpp ./src/Projectile.h ./src/WeaponManager.h ./src/Position.h
			g++ -Wall -c ./src/Projectile.cpp -o ./obj/Projectile.o


./obj/Weapon.o : ./src/Weapon.cpp ./src/Weapon.h ./src/Projectile.h ./src/Position.h ./src/WeaponManager.h ./src/Playership.h ./src/Invaders.h 
			g++ -g -Wall -c ./src/Weapon.cpp -o ./obj/Weapon.o
			

./obj/Playership.o : ./src/Playership.cpp ./src/Playership.h ./src/Projectile.h ./src/WeaponManager.h ./src/Weapon.h ./src/Position.h
			g++ -g -Wall -c ./src/Playership.cpp -o ./obj/Playership.o -lSDL2 -lSDL_mixer


./obj/WeaponManager.o : ./src/WeaponManager.cpp ./src/WeaponManager.h ./src/Position.h ./src/Projectile.h ./src/Weapon.h ./src/Playership.h ./src/Invaders.h ./src/StarblitzGameDisplay.h
			g++ -g -Wall -c ./src/WeaponManager.cpp -o ./obj/WeaponManager.o


./obj/Position.o : ./src/Position.cpp ./src/Position.h
			g++ -Wall -c ./src/Position.cpp -o ./obj/Position.o


./obj/InvadersManager.o : ./src/InvadersManager.cpp ./src/InvadersManager.h ./src/Invaders.h
			g++ -g -Wall -c ./src/InvadersManager.cpp -o ./obj/InvadersManager.o -lSDL2 -lSDL2_image


./obj/Invaders.o : ./src/Invaders.cpp ./src/Invaders.h 
			g++ -g -Wall -c ./src/Invaders.cpp -o ./obj/Invaders.o -lSDL2 


./obj/ProjectileManager.o : ./src/ProjectileManager.cpp ./src/ProjectileManager.h ./src/Position.h ./src/Projectile.h ./src/Weapon.h ./src/Playership.h ./src/Invaders.h ./src/StarblitzGameDisplay.h
			g++ -g -Wall -c ./src/ProjectileManager.cpp -o ./obj/ProjectileManager.o -lSDL2_mixer

clean : 
			rm ./obj/*.o 

realclean :
			rm ./obj/*.o ; rm ./bin/*
