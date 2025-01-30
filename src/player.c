#include <raylib.h>
#include <player.h>

void player_init(Player *player) {
  player->position = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
  player->rotation = 0;
  player->speed = 3;
  player->texture = LoadTexture(RESOURCES_PATH"player.png");
  player->origin = (Vector2){(float)player->texture.width, (float)player->texture.height};
  player->src = (Rectangle){0.0f, 0.0f, (float)player->texture.width, (float)player->texture.width};
  player->dest = (Rectangle){player->position.x, player->position.y, (float)player->texture.width*2, (float)player->texture.height*2};
  player->active = true;
}

// TODO: fazer o player andar em movimento horizontal e vertical, atualmente ele so gira e anda pra cima e para baixo
void player_update(Player *player) {
  player->dest = (Rectangle){player->position.x, player->position.y, (float)player->texture.width*2, (float)player->texture.height*2};
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    player->position.y -= player->speed;
  }
  else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    player->position.y += player->speed;
  }
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    player->rotation -= 2;
  }
  else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    player->rotation += 2;
  }
}

void player_draw(Player *player) {
  DrawTexturePro(player->texture, player->src, player->dest, player->origin, player->rotation, RAYWHITE);
}