#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

class ScoreSystem {
public:
  /**
   * @brief Default constructor for ScoreSystem. Initializes the score to zero.
   */
  ScoreSystem();

  /**
   * @brief Destructor for ScoreSystem.
   */
  ~ScoreSystem();

  /**
   * @brief Initializes the score system, typically resetting the score to zero.
   */
  void init();

  /**
   * @brief Updates the score based on game logic.
   */
  void update();

  /**
   * @brief Draws the score on the screen using SDL.
   */
  void draw();

  /**
   * @brief Increases the score by a specified bonus amount.
   * @param bonus The amount of points to add to the score.
   */
  void incrementScore(int bonus);

  /**
   * @brief Gets the current score value.
   * @return The current score.
   */
  int getScore();

private:
  int score;  // Internal variable to store the score
};

#endif