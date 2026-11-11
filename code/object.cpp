#include "object.h"

Object::Object(sf::RenderWindow* window, sf::Texture* texture)
    : window(window), body(*texture) {
  body.setOrigin(sf::Vector2f(body.getTexture().getSize().x / 2,
                              body.getTexture().getSize().y / 2));
}

bool Object::update(float delta_time) {
  window->draw(body);
  return false;
};