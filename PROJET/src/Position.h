#ifndef POSITION_H
#define POSITION_H

/**
 * @brief Structure representing a 2D position with x and y coordinates.
 */
struct Position {
  /**
   * @brief X-coordinate of the position.
   */
  float x;

  /**
   * @brief Y-coordinate of the position.
   */
  float y;

  /**
   * @brief Constructor to initialize a Position object with specified coordinates.
   * @param _x The initial x-coordinate.
   * @param _y The initial y-coordinate.
   */
  Position(float _x, float _y);

  /**
   * @brief Default constructor to initialize a Position object with zero coordinates.
   */
  Position();
};

/**
 * @brief Overloaded addition operator (+) for Position objects.
 * @param a The first Position object.
 * @param b The second Position object.
 * @return A new Position object representing the sum of the coordinates of a and b.
 */
Position operator+(Position a, Position b);

/**
 * @brief Overloaded multiplication operator (*) between a float and a Position object.
 * @param a The scalar factor.
 * @param b The Position object.
 * @return A new Position object where each coordinate of b is multiplied by a.
 */
Position operator*(float a, Position b);

/**
 * @brief Overloaded multiplication operator (*) between a Position object and a float.
 * @param a The Position object.
 * @param b The scalar factor.
 * @return A new Position object where each coordinate of a is multiplied by b.
 */
Position operator*(Position a, float b);

#endif