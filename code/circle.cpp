#include "circle.h"

Circle::Circle(sf::RenderWindow* window, sf::Texture* texture)
    : Object(window, texture), isPressing(false) {
  body.setPosition(sf::Vector2f(20 + rand() % 560, 20 + rand() % 460));
  direction = sf::Vector2f(100 - rand() % 200, 100 - rand() % 200);
}

bool Circle::update(float delta_time) {
  body.setPosition(body.getPosition() + direction * delta_time);
  if (body.getPosition().x <= 20 || body.getPosition().y <= 20
      ) {
    direction = sf::Vector2f(100 - rand() % 100, 100 - rand() % 100);
  } else {
    if (body.getPosition().x >= 580 || body.getPosition().y >= 480) {
      direction = sf::Vector2f( -(rand() % 100), -(rand() % 100));
    }
  }

  Object::update(delta_time);

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    if (!isPressing) {
      isPressing = true;
      if (body.getGlobalBounds().contains(
              sf::Vector2f(sf::Mouse::getPosition(*window)))) {
        body.setPosition(sf::Vector2f(20 + rand() % 560, 20 + rand() % 460));
        direction = sf::Vector2f(100 - rand() % 200, 100 - rand() % 200);
        return true;
      }
    }
  } else {
    isPressing = false;
  }
  return false;
}