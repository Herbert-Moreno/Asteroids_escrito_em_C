#pragma once
#include <raylib.h>
#ifndef PLAYER_H
#define PLAYER_H

typedef struct player {
  Vector2 position;
  Vector2 origin;
  float rotation;
  float speed;
  Texture2D texture;
  Rectangle dest;
  Rectangle src;
  bool active;
} Player;

void player_init(Player *player, const char *texturapath);
void player_update(Player *player);
void player_draw(Player *player);

#endif //PLAYER_H
