#pragma once
#include <raylib.h>
#include <player.h>
#ifndef BULLET_H
#define BULLET_H

typedef struct Bullet {
  float speed;
  float fireDir;
  Vector2 position;
  Texture2D texture;
  Color color;
  bool active;
} Bullet;

void InitBullet(Bullet* bullet, const char *texturapath);
void BulletDraw(Bullet bullets[], int MAX_BULLETS);
void BulletUpdate(Bullet bullets[], int MAX_BULLETS);
void BulletShoot(Player *player, Bullet bullets[], int MAX_BULLETS);
void UnloadBulletTexture(Bullet bullets[], int MAX_BULLETS);
void ResetBullets(Bullet bullets[], int MAX_BULLETS);

#endif //BULLET_H
