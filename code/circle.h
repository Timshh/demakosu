#pragma once
#include <iostream>
#include "object.h"

class Circle : public Object {
 public:
  Circle(sf::RenderWindow* window, sf::Texture* texture);
  bool update(float delta_time) override;

 private:
  sf::Vector2f direction;
  bool is_pressing;
};