#pragma once
#include <raylib.h>

#ifndef ASTEROID_H
#define ASTEROID_H

typedef struct asteroid {
  Texture2D texture;
  Vector2 position;
  Vector2 velocityDir;
  Vector2 origin;
  Rectangle dest;
  Rectangle src;
  int scale;
  float rotation;
  bool active;
} Asteroid;

void AsteroidInit(Asteroid *asteroid, const char *texturapath, Player *player);
void AsteroidUpdate(Asteroid asteroids[], int MAX_ASTEROIDS, Bullet bullets[], int MAX_BULLETS, Player *player);
void AsteroidDraw(Asteroid asteroids[], int MAX_ASTEROIDS);
void GetAsteroidSpawn(Asteroid *asteroid);
void UnloadAsteroidsTexture(Asteroid asteroid[], int MAX_ASTEROIDS);
void CreateAsteroid(Asteroid asteroids[], int MAX_ASTEROIDS);
void ResetAsteroids(Asteroid asteroids[], int MAX_ASTEROIDS, Player *player);

#endif //ASTEROID_H
