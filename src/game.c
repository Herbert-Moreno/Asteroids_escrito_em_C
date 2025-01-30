#include <stdio.h>
#include <game.h>
#include <player.h>
#include <raylib.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
Player player;

void game_init(void){
  printf("Game Initializing...\n");

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Asteroids em C");
  SetTargetFPS(60);
  
  player_init(&player);
}

void game_update(void){
  while(!WindowShouldClose()){
    player_update(&player);

    BeginDrawing();

      ClearBackground(BLACK);
      game_draw();

    EndDrawing();

    if (IsKeyDown(KEY_ESCAPE)) {
      break;
    }
  }
  // Quando o While for falso ou a tecla esc for apertada ele é quebrado e o programa remove as textura da Ram
  // e mata a tarefa da janela
  UnloadTexture(player.texture);
  CloseWindow();
}

void game_draw(void) {
  player_draw(&player);
}