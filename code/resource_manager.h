#pragma once
#include <SFML/Graphics/Font.hpp>

class ResourceManager {
 public:
  ResourceManager();
  sf::Font* getFont();
  sf::Texture* getCircleTexture();

 private:
  sf::Font font;
  sf::Texture circle;
};