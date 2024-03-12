#include "ScoreSystem.h"


    ScoreSystem::ScoreSystem() {
        score = 0;
    };
    ScoreSystem::~ScoreSystem() {
        score = 0;
    };

    void ScoreSystem::init() {
        score = 0; // Remet le score à zéro à l'initialisation
    };

    void ScoreSystem::update(){
        // logique du score dans le jeu, à définir
    };
    void ScoreSystem::draw() {
        // Affichage du score avec SDL
    };
    void ScoreSystem::incrementScore(int newscore){
        score += newscore;
    };
    int ScoreSystem::getScore() {
        return score;
    };
