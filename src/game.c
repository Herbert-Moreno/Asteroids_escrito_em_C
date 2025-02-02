#include <stdio.h>
#include <game.h>
#include <background.h>
#include <player.h>
#include <raylib.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
Player player;
Background background1;
MovableBackground background2;
Background background3;

char *texturas[5];

void game_init(void){
  printf("Game Initializing...\n");

  texturas[0] = RESOURCES_PATH"player.png";
  texturas[1] = RESOURCES_PATH"background1.png";
  texturas[2] = RESOURCES_PATH"background2.png";
  texturas[3] = RESOURCES_PATH"background3.png";

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Asteroids em C");
  SetTargetFPS(60);
  
  player_init(&player, texturas[0]);
  Background_init(&background1, texturas[1]);
  MovableBackground_init(&background2, texturas[2]);
  Background_init(&background3, texturas[3]);
}

void game_update(void){
  while(!WindowShouldClose()){
    player_update(&player);
    MovableBackground_update(&background2);

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
  UnloadTexture(background1.texture);
  UnloadTexture(background2.texture);
  UnloadTexture(background3.texture);
  CloseWindow();
}

void game_draw(void) {
  Background_draw(&background1);
  MovableBackground_draw(&background2);
  Background_draw(&background3);
  player_draw(&player);
}