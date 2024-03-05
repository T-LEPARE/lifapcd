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
        score = 0; // Remet le score à zéro à l'initialisation
    };

    void update(){
        // logique du score dans le jeu, à définir
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