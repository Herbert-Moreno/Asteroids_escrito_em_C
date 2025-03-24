#pragma once
#include <raylib.h>
#ifndef PLAYER_H
#define PLAYER_H

typedef struct player {
  Vector2 position;
  Vector2 origin;
  Vector2 look_direction;
  float rotation;
  float speed;
  Texture2D texture;
  Rectangle dest;
  Rectangle src;
  bool active;
} Player;

void PlayerInit(Player *player, const char *texturapath);
void PlayerUpdate(Player *player);
void PlayerDraw(Player *player);
void ResetPlayer(Player *player);

#endif //PLAYER_H
