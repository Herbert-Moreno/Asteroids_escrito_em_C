#include <background.h>
#include <raylib.h>

void BackgroundInit(Background *background, const char *texturapath) {
  background->position = (Vector2){0,0};
  background->texture = LoadTexture(texturapath);
  background->color = WHITE;
}

void BackgroundDraw(Background *background) {
  DrawTextureEx(background->texture, background->position, 0, 2.2, background->color);
}

void MovableBackgroundInit(MovableBackground *movableBackground, const char *texturapath) {
  movableBackground->position = (Vector2){0,0};
  movableBackground->scrollspeed = 10;
  movableBackground->texture = LoadTexture(texturapath);
  movableBackground->dest = (Rectangle){movableBackground->position.x, movableBackground->position.y, movableBackground->texture.width*2.5, movableBackground->texture.height*2.5};
  movableBackground->src = (Rectangle){0, 0, movableBackground->texture.width, movableBackground->texture.height};
  movableBackground->color = WHITE;
}
void MovableBackgroundUpdate(MovableBackground *movableBackground) {
  float deltaTime = GetFrameTime(); // Tempo desde o último quadro
  movableBackground->movePos.x -= movableBackground->scrollspeed * deltaTime; // Move a textura no eixo x
  movableBackground->movePos.y -= movableBackground->scrollspeed * deltaTime / 2; // Move a textura no eixo y
  movableBackground->src = (Rectangle){movableBackground->movePos.x, movableBackground->movePos.y, movableBackground->texture.width, movableBackground->texture.height};
}
void MovableBackgroundDraw(MovableBackground *movableBackground) {
  DrawTexturePro(movableBackground->texture, movableBackground->src, movableBackground->dest, (Vector2){0,0}, 0.0f, WHITE);
}