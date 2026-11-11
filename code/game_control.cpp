#include "game_control.h"

GameControl::GameControl()
    : state(GameStates::kMenu),
      high_score(0),
      window(sf::RenderWindow(sf::VideoMode({600, 500}), "Striker",
                              sf::State::Windowed)),
      manager(ResourceManager()),
      menu(&window, manager.getFont()) {

  srand(std::time(NULL));
  gamemode.reset(new Gamemode(&window, &manager));
  state = GameStates::kMenu;
}

void GameControl::run() {
  while (window.isOpen()) {
    if (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();
    }
    update();
  }
}

void GameControl::update() {
  float delta_time = time.restart().asSeconds();
  window.clear();
  switch (state) {
    case GameStates::kMenu:
      if (menu.update()) {
        gamemode.reset(new Gamemode(&window, &manager));
        state = GameStates::kPlaying;
      }
      break;
    case GameStates::kPlaying:
      if (gamemode->update(delta_time)) {
        state = GameStates::kMenu;
        high_score = std::max(gamemode->getScore(), high_score);
        menu.updateScore(high_score);
      }
      break;
  }
  window.display();
};