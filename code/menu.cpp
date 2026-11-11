#include "menu.h"

Menu::Menu(sf::RenderWindow* window, sf::Font* font)
    : hi_text(*font, "Hi score: 0", 30),
      restart_text(*font, "Press R to start", 30), window(window) {
  hi_text.setPosition(sf::Vector2f(240, 280));
  restart_text.setPosition(sf::Vector2f(220, 220));
}

bool Menu::update() {
  window->draw(restart_text);
  window->draw(hi_text);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
    return true;
  }
  return false;
}
void Menu::updateScore(int score) { hi_text.setString("Hi score: " + std::to_string(score)); };