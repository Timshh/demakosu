#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "resource_manager.h"

class Object {
 public:
  Object(sf::RenderWindow* window, sf::Texture* texture);
  virtual bool update(float delta_time);

 protected:
  sf::RenderWindow* window;
  sf::Sprite body;
};