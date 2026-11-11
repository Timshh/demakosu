#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Menu {
 public:
  Menu(sf::RenderWindow* window, sf::Font* font);
  bool update();
  void updateScore(int score);

 private:
  sf::Text hi_text, restart_text;
  sf::RenderWindow* window;
};