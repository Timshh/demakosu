#include "gamemode.h"

Gamemode::Gamemode(sf::RenderWindow* window, ResourceManager* manager)
    : window(window),
      manager(manager),
      score_text(*manager->getFont(), "Score: 0", 20),
      time_text(*manager->getFont(), "Time: 30", 20),
      score(0),
      timer(10) {
  score_text.setPosition(sf::Vector2f(10, 10));
  time_text.setPosition(sf::Vector2f(520, 10));
  for (int i = 0; i < 5; i++) {
    circles.push_back(Circle(window, manager->getCircleTexture()));
  }
}

bool Gamemode::update(float delta_time) {

  bool did_miss = false;
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    if (!is_pressing) {
      is_pressing = true;
      did_miss = true;
    }
  } else {
    is_pressing = false;
  }
  for (Circle& circle : circles) {
    if (circle.update(delta_time)) {
      did_miss = false;
      score += 1;
      score_text.setString("Score: " + std::to_string(score));
    }
  }
  if (did_miss) {
    timer -= 1;
  }

  timer -= delta_time;
  time_text.setString("Time: " + std::to_string(int(timer)));
  if (timer <= 0) {
    return true;
  }

  window->draw(score_text);
  window->draw(time_text);
  return false;
}

int Gamemode::getScore() { return score; }
