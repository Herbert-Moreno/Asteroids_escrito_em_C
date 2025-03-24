#include <math.h>
#include <raylib.h>
#include <player.h>
#include <raymath.h>

void PlayerInit(Player *player, const char *texturapath) {
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
void PlayerUpdate(Player *player) {
  if (player->active) {
    player->dest = (Rectangle){player->position.x, player->position.y, (float)player->texture.width*2, (float)player->texture.height*2};
    Vector2 mousePosition = GetMousePosition();
    // Calcula o vetor direção do sprite para o mouse
    player->look_direction = (Vector2){mousePosition.x - player->position.x, mousePosition.y - player->position.y};
    // Calcula o ângulo de rotação com base na direção
    float rotation = atan2f(player->look_direction.y, player->look_direction.x) * RAD2DEG + 90.0f;
    Vector2 player_move = {0.0f,0.0f};

    player->rotation = rotation;

    if (IsKeyDown(KEY_LEFT) && player->position.x >= 0 + (float)player->texture.width ||
      IsKeyDown(KEY_A) && player->position.x >= 0 + (float)player->texture.width) {
      player_move.x = -1;
    }
    else if (IsKeyDown(KEY_RIGHT) && player->position.x <= (float)GetScreenWidth() - (float)player->texture.width ||
      IsKeyDown(KEY_D) && player->position.x <= (float)GetScreenWidth() - (float)player->texture.width) {
      player_move.x = 1;
    }
    if (IsKeyDown(KEY_UP) && player->position.y >= 0 + (float)player->texture.width ||
      IsKeyDown(KEY_W) && player->position.y >= 0 + (float)player->texture.width) {
      player_move.y = -1;
    }
    else if (IsKeyDown(KEY_DOWN) && player->position.y <= (float)GetScreenWidth() - (float)player->texture.width ||
      IsKeyDown(KEY_S) && player->position.y <= (float)GetScreenWidth() - (float)player->texture.width) {
      player_move.y = 1;
    }
    if (player_move.x != 0 || player_move.y != 0) {
      player_move = Vector2Normalize(player_move);
      player_move = (Vector2){player_move.x * (GetFrameTime() * player->speed), player_move.y * (GetFrameTime() * player->speed)};
      player->position = (Vector2){player->position.x + player_move.x, player->position.y + player_move.y};
    }
  }
}

void PlayerDraw(Player *player) {
  if (player->active) {
    DrawTexturePro(player->texture, player->src, player->dest, player->origin, player->rotation, RAYWHITE);
  }
}

void ResetPlayer(Player *player) {
  player->position = (Vector2){(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f};
  player->rotation = 0;
  player->active = true;
}