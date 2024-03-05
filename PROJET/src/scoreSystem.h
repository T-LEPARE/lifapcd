#ifndef SCORE_SYSTEME_H
#define SCORE_SYSTEME_H

class scoreSystem {
public:
    scoreSystem();
    ~scoreSystem();
    void init();
    void update();
    void draw();
    void incrementScore(int);
    int getScore();
private:
    int score;
};

#endif