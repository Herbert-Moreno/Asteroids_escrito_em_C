#include <math.h>
#include <raylib.h>
#include <player.h>

#include "raymath.h"

void player_init(Player *player, const char *texturapath) {
  player->position = (Vector2){(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f};
  player->rotation = 0;
  player->speed = 160;
  player->texture = LoadTexture(texturapath);
  player->origin = (Vector2){(float)player->texture.width, (float)player->texture.height};
  player->src = (Rectangle){0.0f, 0.0f, (float)player->texture.width, (float)player->texture.width};
  player->dest = (Rectangle){player->position.x, player->position.y, (float)player->texture.width*2, (float)player->texture.height*2};
  player->active = true;
}

// TODO: fazer o player andar em movimento horizontal e vertical, atualmente ele so gira e anda pra cima e para baixo
void player_update(Player *player) {
  player->dest = (Rectangle){player->position.x, player->position.y, (float)player->texture.width*2, (float)player->texture.height*2};
  Vector2 mousePosition = GetMousePosition();
  // Calcula o vetor direção do sprite para o mouse
  Vector2 direction = {mousePosition.x - player->position.x, mousePosition.y - player->position.y};
  // Calcula o ângulo de rotação com base na direção
  float rotation = atan2f(direction.y, direction.x) * RAD2DEG + 90;
  Vector2 player_move = {0.0f,0.0f};

  player->rotation = rotation;

  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    player_move.y = -1;
  }
  else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    player_move.y = 1;
  }
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    player_move.x = -1;
  }
  else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    player_move.x = 1;
  }
  if (player_move.x != 0 || player_move.y != 0) {
    player_move = Vector2Normalize(player_move);
    player_move = (Vector2){player_move.x * (GetFrameTime() * player->speed), player_move.y * (GetFrameTime() * player->speed)};
    player->position = (Vector2){player->position.x + player_move.x, player->position.y + player_move.y};
  }
}

void player_draw(Player *player) {
  DrawTexturePro(player->texture, player->src, player->dest, player->origin, player->rotation, RAYWHITE);
}