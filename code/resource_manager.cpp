#include "resource_manager.h"

ResourceManager::ResourceManager() {
  circle.loadFromFile("data/circle.png");
  font.openFromFile("data/roboto.ttf");
}

sf::Font* ResourceManager::getFont() { return &font; }

sf::Texture* ResourceManager::getCircleTexture() { return &circle; }
