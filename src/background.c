#include <background.h>
#include <raylib.h>

void Background_init(Background *background, const char *texturapath) {
  background->position = (Vector2){0,0};
  background->texture = LoadTexture(texturapath);
  background->color = WHITE;
}

void Background_draw(Background *background) {
  DrawTextureEx(background->texture, background->position, 0, 2.5, background->color);
}

void MovableBackground_init(MovableBackground *movableBackground, const char *texturapath) {
  movableBackground->position = (Vector2){0,0};
  movableBackground->scrollspeed = 10;
  movableBackground->texture = LoadTexture(texturapath);
  movableBackground->src = (Rectangle){0, 0, movableBackground->texture.width, movableBackground->texture.height};
  movableBackground->color = WHITE;
}
void MovableBackground_update(MovableBackground *movableBackground) {
  float deltaTime = GetFrameTime(); // Tempo desde o último quadro
  movableBackground->position.x -= movableBackground->scrollspeed * deltaTime; // Move a textura no eixo x
  movableBackground->position.y -= movableBackground->scrollspeed * deltaTime / 2; // Move a textura no eixo y
  movableBackground->dest = (Rectangle){movableBackground->position.x, movableBackground->position.y, movableBackground->texture.width*2.5, movableBackground->texture.height*2.5};
}
void MovableBackground_draw(MovableBackground *movableBackground) {
  DrawTexturePro(movableBackground->texture, movableBackground->src, movableBackground->dest, (Vector2){0,0}, 0.0f, WHITE);
}