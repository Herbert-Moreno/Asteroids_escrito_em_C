#pragma once
#include <raylib.h>
#include <game.h>
#ifndef UI_H
#define UI_H

typedef struct UiButton{
  Texture2D textureNormal;
  Texture2D textureHovered;
  Texture2D textureSelected;
  Vector2 position;
  int size;
  int rotation;
  Color color;
  bool hovered;
  bool active;
} UiButton;

typedef struct UI{
  Texture2D texture;
  Vector2 position;
  int size;
  int rotation;
  Color color;
  bool active;
} UI;

void UiInit(UI* ui, Vector2 position, int size, const char *texture);
void UiUpdate(UI* ui);
void UiDraw(UI *ui);

void UiButtonInit(UiButton* ui, Vector2 position, int size, char *texture, char *textureHovered);
void UiButtonUpdate(UiButton* ui, enum GameState _state);
void UiButtonDraw(UiButton* ui);

#endif //UI_H
