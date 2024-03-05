#include "ScoreSystem.h"

class ScoreSystem {
public:
    ScoreSystem() {
        score = 0;
    };
    ~ScoreSystem() {
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