#include <iostream>
#include "player.h"

Player::Player(const Snake* snake, const SDL_Point* food) : snake(snake), food(food){
    std::cout << "Player's Constructor called.\n";
};

Player::~Player() {
    std::cout << "Player's Destructor called.\n";
}

void Player::play()
{
    // Find snake's head on the grid
    int cur_x = static_cast<int>(snake->head_x);
    int cur_y = static_cast<int>(snake->head_y);

    if (cur_x != food->x && cur_y != food->y) return; // Continue moving  
    if (cur_x == food->x && cur_y == food->y) return; // Grab food and continue moving
    
    // Prepare an event
    SDL_Event sdlevent;
    sdlevent.type = SDL_KEYDOWN;

    if (cur_x == food->x) 
    {
        if (cur_y > food->y) sdlevent.key.keysym.sym = SDLK_UP;
        else sdlevent.key.keysym.sym = SDLK_DOWN;
    }
    else // cur_y == food.y
    {
        if (cur_x > food->x) sdlevent.key.keysym.sym = SDLK_LEFT;
        else sdlevent.key.keysym.sym = SDLK_RIGHT;
    }

    SDL_PushEvent(&sdlevent);
}