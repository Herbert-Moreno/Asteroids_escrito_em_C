#pragma once
#include <raylib.h>
#ifndef BACKGROUND_H
#define BACKGROUND_H

typedef struct background {
    Vector2 position;
    Texture2D texture;
    Color color;
} Background;

typedef struct movablebackground {
    float scrollspeed;
    Vector2 position;
    Texture2D texture;
    Rectangle src;
    Rectangle dest;
    Color color;
} MovableBackground;

void Background_init(Background *background, const char *texturapath);
void Background_draw(Background *background);

void MovableBackground_init(MovableBackground *background, const char *texturapath);
void MovableBackground_update(MovableBackground *background);
void MovableBackground_draw(MovableBackground *background);

#endif //BACKGROUND_H
