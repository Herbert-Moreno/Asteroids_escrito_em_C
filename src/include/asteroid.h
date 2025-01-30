#include <raylib.h>

#ifndef ASTEROID_H
#define ASTEROID_H

typedef struct asteroid {
  Vector2 position;
  Vector2 origin;
  float rotation;
  float speed;
  Texture2D texture;
  Rectangle dest;
  Rectangle src;
  bool active;
} Asteroid;

void asteroid_init(Asteroid *asteroid);
void asteroid_update(Asteroid *asteroid);
void asteroid_draw(Asteroid *asteroid);

#endif //ASTEROID_H
