#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int kMode;
  std::cout << "Welcome to the Snake Game!\n";
  std::cout << "Press 1 if you would like to play the game yourself.\n";
  std::cout << "Press 2 if you would like to watch a simple AI play the game.\n";
  std::cin >> kMode;

  while (kMode != 1 && kMode != 2) 
  {
    std::cout << "Invalid choice.\n";
    std::cout << "Press 1 if you would like to play the game yourself.\n";
    std::cout << "Press 2 if you would like to watch a simple AI play the game.\n";
    std::cin >> kMode;
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, kMode); 
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}