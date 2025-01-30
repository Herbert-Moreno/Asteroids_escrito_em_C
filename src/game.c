#include <stdio.h>
#include <game.h>
#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void game_init(void){
  printf("Game Initializing...\n");
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Asteroids em C");
  SetTargetFPS(60);
}

void game_update(void){
  while(!WindowShouldClose()){
    BeginDrawing();
      ClearBackground(BLACK);
      game_draw();
    EndDrawing();
  }
  CloseWindow();
}

void game_draw(void) {
  //printf("Game Drawing...\n");
}