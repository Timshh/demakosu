#pragma once

#include <memory>
#include <ctime>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "gamemode.h"
#include "menu.h"
#include "resource_manager.h"

enum class GameStates { kMenu, kPlaying };

class GameControl {
 public:
  GameControl();
  void run();
  void update();

 private:
  Menu menu;
  sf::RenderWindow window;
  sf::Clock time;
  ResourceManager manager;
  std::unique_ptr<Gamemode> gamemode;
  GameStates state;
  int high_score;
};