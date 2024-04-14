#ifndef STARBLITZGAMEDISPLAY_H
#define STARBLITZGAMEDISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Display {
private:
  static int DIMW;  // Static member variable for display width
  static int DIMH;  // Static member variable for display height
  SDL_Surface* surface;  // Pointer to an SDL_Surface representing the background image
  SDL_Texture* texture;  // Pointer to an SDL_Texture representing the background image (for rendering)
  bool shouldRender;     // Flag indicating whether rendering should occur

public:
  /**
   * @brief Constructor for Display. Initializes the display with a background image.
   * @param renderer Reference to an SDL_Renderer object used for texture creation.
   */
  Display(SDL_Renderer* renderer);

  /**
   * @brief Destructor for Display. Frees resources (surface and texture).
   */
  ~Display();

  /**
   * @brief Static function to get the display width.
   * @return The display width.
   */
  static int getDIMW();

  /**
   * @brief Static function to get the display height.
   * @return The display height.
   */
  static int getDIMH();

  /**
   * @brief Static function to set the display width.
   * @param DIMW The new display width.
   */
  static void setDIMW(int DIMW);

  /**
   * @brief Static function to set the display height.
   * @param DIMH The new display height.
   */
  static void setDIMH(int DIMH);

  /**
   * @brief Renders the display background image on the provided renderer.
   * @param renderer Reference to an SDL_Renderer object.
   */
  void render(SDL_Renderer* renderer);

  /**
   * @brief Gets the display's texture object.
   * @return The display's texture object.
   */
  SDL_Texture* getTexture();

  /**
   * @brief Gets the display's surface object.
   * @return The display's surface object.
   */
  SDL_Surface* getSurface();

  /**
   * @brief Sets the display's texture object.
   * @param _texture The new texture object.
   */
  void setTexture(SDL_Texture* _texture);

  /**
   * @brief Sets the display's surface object.
   * @param _surface The new surface object.
   */
  void setSurface(SDL_Surface* _surface);
};

#endif