#include <stdio.h>
#include <game.h>
#include <background.h>
#include <player.h>
#include <bullet.h>
#include <asteroid.h>
#include <raylib.h>
#include <stdlib.h>
#include <ui.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define MAX_BULLETS 3
#define MAX_ASTEROIDS 10
#define MAX_UI_OBJECTS 3

int playerScore = 0;

static Player player;
static Background background1;
static MovableBackground background2;
static Background background3;

char *texturas[13];
static Bullet bullets[MAX_BULLETS];
static Asteroid asteroids[MAX_ASTEROIDS];
static UI bulletsIcon[MAX_UI_OBJECTS];

static UI titleName;
static UiButton titleButton;
static UI gameOverTitle;
static UiButton menuButton;

static GameState state = Menu;

void GameInit(void){
  printf("Game Initializing...\n");

  texturas[0] = RESOURCES_PATH"player.png";
  texturas[1] = RESOURCES_PATH"background1.png";
  texturas[2] = RESOURCES_PATH"background2.png";
  texturas[3] = RESOURCES_PATH"background3.png";
  texturas[4] = RESOURCES_PATH"shot.png";
  texturas[5] = RESOURCES_PATH"asteroid.png";
  texturas[6] = RESOURCES_PATH"bullet_ui.png";
  texturas[7] = RESOURCES_PATH"name_ui.png";
  texturas[8] = RESOURCES_PATH"start_ui.png";
  texturas[9] = RESOURCES_PATH"start_pressed_ui.png";
  texturas[10] = RESOURCES_PATH"gameover_ui.png";
  texturas[11] = RESOURCES_PATH"menu_ui.png";
  texturas[12] = RESOURCES_PATH"menu_pressed_ui.png";

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Asteroids em C");
  SetTargetFPS(60);
  
  PlayerInit(&player, texturas[0]);
  BackgroundInit(&background1, texturas[1]);
  MovableBackgroundInit(&background2, texturas[2]);
  BackgroundInit(&background3, texturas[3]);
  UiInit(&titleName, (Vector2) {(float)GetScreenWidth()/5, (float)GetScreenHeight()/5}, 5, texturas[7]);
  UiButtonInit(&titleButton, (Vector2) {(float)GetScreenWidth()/2.2f, (float)GetScreenHeight()/1.5f}, 4, texturas[8], texturas[9]);
  UiInit(&gameOverTitle, (Vector2) {(float)GetScreenWidth()/6, (float)GetScreenHeight()/8}, 6, texturas[10]);
  UiButtonInit(&menuButton, (Vector2) {(float)GetScreenWidth()/2.2f, (float)GetScreenHeight()/1.5f}, 4, texturas[11], texturas[12]);

  for (int b = 0; b < MAX_BULLETS; b++) {
    InitBullet(&bullets[b], texturas[4]);
  }

  for (int a = 0; a < MAX_ASTEROIDS; a++) {
    AsteroidInit(&asteroids[a], texturas[5], &player);
  }

  for (int u = 0; u < MAX_UI_OBJECTS; u++) {
    UiInit(&bulletsIcon[u], (Vector2) {(float)((GetScreenWidth() - 40) -(u * 30)), 10}, 3, texturas[6]);
  }
}

void GameUpdate(void){
  while(!WindowShouldClose()){
    MovableBackgroundUpdate(&background2);

    if (state == Menu) {
      UiButtonUpdate(&titleButton, (GameState){Game});
    } else if (state == Game) {
      PlayerUpdate(&player);

      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        BulletShoot(&player, bullets, MAX_BULLETS);
      }

      CreateAsteroid(asteroids, MAX_ASTEROIDS);

      for (int u = 0; u < MAX_UI_OBJECTS; u++) {
        if (bullets[u].active) {
          bulletsIcon[u].active = false;
        } else {
          bulletsIcon[u].active = true;
        }
      }

      BulletUpdate(bullets, MAX_BULLETS);
      AsteroidUpdate(asteroids, MAX_ASTEROIDS, bullets, MAX_BULLETS, &player);
    } else if (state == GameOver) {
      UiButtonUpdate(&menuButton, (GameState){Menu});
    }

    BeginDrawing();

      ClearBackground(BLACK);
      GameDraw();

    EndDrawing();

    if (IsKeyDown(KEY_ESCAPE)) {
      break;
    }
  }

  // Quando o While for falso ou a tecla esc for apertada ele é quebrado e o programa remove as textura da Ram
  // e mata a tarefa da janela

  //Descarregar da memoria textura do player
  UnloadTexture(player.texture);

  //Descarregar da memoria textura do background
  UnloadTexture(background1.texture);
  UnloadTexture(background2.texture);
  UnloadTexture(background3.texture);

  //Descarregar da memoria textura das Balas
  UnloadBulletTexture(bullets, MAX_BULLETS);

  //Descarregar da memoria textura dos asteroids
  UnloadAsteroidsTexture(asteroids, MAX_ASTEROIDS);

  //Descarregar da memoria textura de Ui
  UnloadTexture(titleName.texture);
  UnloadTexture(gameOverTitle.texture);

  //Descarregar da memoria textura dos Botões
  UnloadTexture(titleButton.textureNormal);
  UnloadTexture(titleButton.textureHovered);
  UnloadTexture(titleButton.textureSelected);
  UnloadTexture(menuButton.textureNormal);
  UnloadTexture(menuButton.textureHovered);
  UnloadTexture(menuButton.textureSelected);

  for (int u = 0; u < MAX_UI_OBJECTS; u++) {
    UnloadTexture(bulletsIcon[u].texture);
  }
  //Mata o contexto e a janela do app
  CloseWindow();
}

void GameDraw(void) {
  BackgroundDraw(&background1);
  MovableBackgroundDraw(&background2);
  BackgroundDraw(&background3);

  switch (state) {
    case Menu:
      UiDraw(&titleName);
      UiButtonDraw(&titleButton);
      break;

    case Game:
      PlayerDraw(&player);
      BulletDraw(bullets, MAX_BULLETS);
      AsteroidDraw(asteroids, MAX_ASTEROIDS);
      DrawText(TextFormat("SCORE: %i\n", playerScore), 10, 10, 50, WHITE);
      for (int u = 0; u < MAX_UI_OBJECTS; u++) {
        UiDraw(&bulletsIcon[u]);
      }
      break;

    case GameOver:
      UiDraw(&gameOverTitle);
      DrawText(TextFormat("SCORE: %i\n", playerScore), GetScreenWidth()/2.5, GetScreenHeight()/2, 50, WHITE);
      UiButtonDraw(&menuButton);
      break;

    default:
      break;
  }
}

void SetState(GameState _state) {
  switch (_state) {
    case Menu:
      break;

    case Game:
      ResetAsteroids(asteroids, MAX_ASTEROIDS, &player);
      ResetBullets(bullets, MAX_BULLETS);
      ResetPlayer(&player);
      playerScore = 0;
      break;

    case GameOver:
      break;

    default:
      break;
  }
  state = _state;
}

void ChangeScore(int _increment) {
  playerScore += _increment;
}