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
    Vector2 movePos;
    Texture2D texture;
    Rectangle src;
    Rectangle dest;
    Color color;
} MovableBackground;

void BackgroundInit(Background *background, const char *texturapath);
void BackgroundDraw(Background *background);

void MovableBackgroundInit(MovableBackground *background, const char *texturapath);
void MovableBackgroundUpdate(MovableBackground *background);
void MovableBackgroundDraw(MovableBackground *background);

#endif //BACKGROUND_H
