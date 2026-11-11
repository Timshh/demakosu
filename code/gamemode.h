#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

#include "circle.h"

class Gamemode {
 public:
  Gamemode(sf::RenderWindow* window, ResourceManager* manager);
  bool update(float delta_time);
  int getScore();

 private:
  sf::Text score_text, time_text;
  ResourceManager* manager;
  sf::RenderWindow* window;
  std::vector<Circle> circles;
  int score;
  float timer;
};