<<<<<<< HEAD
#include "./scoreSystem.h"
=======
#include "ScoreSystem.h";
>>>>>>> 63755c6 (modif player.h et Invaders.h)

class scoreSystem {
public:
    scoreSystem() {
        score = 0;
    };
    ~scoreSystem() {
        score = 0;
    };

    void init() {
    };

    void update(){

    };
    void draw() {
        // Affichage du score avec SDL
    };
    void incrementScore(int newscore){
        score += newscore;
    };
    int getScore() {
        return score;
    };
private:
    int score;
};