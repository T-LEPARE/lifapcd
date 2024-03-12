all :./bin/StarblitzGame

./bin/StarblitzGame : ./obj/StarblitzGameDisplay.o ./obj/StarblitzGameLogic.o ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o
			g++ -g ./obj/StarblitzGameDisplay.o ./obj/StarblitzGameLogic.o ./obj/ScoreSystem.o ./obj/Projectile.o ./obj/Position.o ./obj/Playership.o ./obj/Invaders.o -o ./bin/StarblitzGame -lSDL2


./obj/StarblitzGameLogic.o : ./src/StarblitzGameLogic.cpp ./src/StarblitzGameLogic.h
			g++ -Wall -c ./src/StarblitzGameLogic.cpp -o ./obj/StarblitzGameLogic.o



./obj/StarblitzGameDisplay.o : ./src/StarblitzGameDisplay.cpp ./src/StarblitzGameDisplay.h
			g++ -Wall -c ./src/StarblitzGameDisplay.cpp -o ./obj/StarblitzGameDisplay.o -lSDL2



./obj/ScoreSystem.o : ./src/ScoreSystem.cpp ./src/ScoreSystem.h
			g++ -Wall -c ./src/ScoreSystem.cpp -o ./obj/ScoreSystem.o



./obj/Projectile.o : ./src/Projectile.cpp ./src/Projectile.h
			g++ -Wall -c ./src/Projectile.cpp -o ./obj/Projectile.o 



./obj/Position.o : ./src/Position.cpp ./src/Position.h
			g++ -Wall -c ./src/Position.cpp -o ./obj/Position.o


./obj/Playership.o : ./src/Playership.cpp ./src/Playership.h
			g++ -g -Wall -c ./src/Playership.cpp -o ./obj/Playership.o -lSDL2


./obj/Invaders.o : ./src/Invaders.cpp ./src/Invaders.h 
			g++ -g -Wall -c ./src/Invaders.cpp -o ./obj/Invaders.o

clean : 
		rm ./obj/*.o 

veryclean :
		rm ./bin/*
