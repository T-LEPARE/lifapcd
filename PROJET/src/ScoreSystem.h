#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H


class ScoreSystem {
    public:
        ScoreSystem();
        ~ScoreSystem();
        void init();
        void update();
        void draw();
        void incrementScore(int);
        int getScore();
    private:
        int score;
};

#endif