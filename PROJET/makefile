all :./bin/StarblitzGame

./bin/StarblitzGame : ./obj/StarblitzGameDisplay.o ./obj/StarblitzGameLogic.o ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o ./obj/Partie.o ./obj/InvadersManager.o ./obj/Weapon.o 
			g++ -g ./obj/StarblitzGameDisplay.o ./obj/StarblitzGameLogic.o ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o ./obj/Partie.o ./obj/InvadersManager.o ./obj/Weapon.o -o ./bin/StarblitzGame -lSDL2 -lSDL2_image


./obj/Partie.o : ./src/Partie.cpp ./src/Playership.h ./src/Position.h ./src/Projectile.h ./src/Invaders.h ./src/StarblitzGameDisplay.h
			g++ -Wall -c ./src/Partie.cpp -o ./obj/Partie.o

./obj/StarblitzGameLogic.o : ./src/StarblitzGameLogic.cpp ./src/StarblitzGameLogic.h
			g++ -Wall -c ./src/StarblitzGameLogic.cpp -o ./obj/StarblitzGameLogic.o



./obj/StarblitzGameDisplay.o : ./src/StarblitzGameDisplay.cpp ./src/StarblitzGameDisplay.h ./src/Playership.h ./src/Projectile.h ./src/Weapon.h
			g++ -Wall -c ./src/StarblitzGameDisplay.cpp -o ./obj/StarblitzGameDisplay.o -lSDL2 -lSDL2_image



./obj/ScoreSystem.o : ./src/ScoreSystem.cpp ./src/ScoreSystem.h
			g++ -Wall -c ./src/ScoreSystem.cpp -o ./obj/ScoreSystem.o



./obj/Projectile.o : ./src/Projectile.cpp ./src/Projectile.h ./src/Projectile.h
			g++ -Wall -c ./src/Projectile.cpp -o ./obj/Projectile.o 



./obj/Position.o : ./src/Position.cpp ./src/Position.h
			g++ -Wall -c ./src/Position.cpp -o ./obj/Position.o


./obj/Playership.o : ./src/Playership.cpp ./src/Playership.h ./src/Projectile.h ./src/Weapon.h
			g++ -g -Wall -c ./src/Playership.cpp -o ./obj/Playership.o -lSDL2

./obj/InvadersManager.o : ./src/InvadersManager.cpp ./src/InvadersManager.h ./src/Invaders.h
			g++ -g -Wall -c ./src/InvadersManager.cpp -o ./obj/InvadersManager.o -lSDL2 -lSDL2_image

./obj/Invaders.o : ./src/Invaders.cpp ./src/Invaders.h 
			g++ -g -Wall -c ./src/Invaders.cpp -o ./obj/Invaders.o -lSDL2 

./obj/Weapon.o : ./src/Weapon.cpp ./src/Weapon.h ./src/Projectile.h ./src/Position.h
			g++ -g -Wall -c ./src/Weapon.cpp -o ./obj/Weapon.o

clean : 
		rm ./obj/*.o 

realclean :
		rm ./obj/*.o ; rm ./bin/*
