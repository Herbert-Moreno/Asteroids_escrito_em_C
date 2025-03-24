#include <raylib.h>
#include <ui.h>
#include <game.h>

void UiInit(UI* ui, Vector2 position, int size, const char *texture) {
    ui->position = position;
    ui->size = size;
    ui->rotation = 0;
    ui->texture = LoadTexture(texture);
    ui->active = true;
}

void UiUpdate(UI* ui);

void UiDraw(UI *ui) {
  if (ui->active) {
    DrawTextureEx(ui->texture, ui->position, ui->rotation, ui->size, WHITE);
  }
}

void UiButtonInit(UiButton* ui, Vector2 position, int size, char *textureNormal, char *textureHovered) {
    ui->position = position;
    ui->size = size;
    ui->rotation = 0;
    ui->textureNormal = LoadTexture(textureNormal);
    ui->textureHovered = LoadTexture(textureHovered);
    ui->textureSelected = LoadTexture(textureNormal);
    ui->active = true;
}

void UiButtonUpdate(UiButton* ui, GameState _state) {
  Rectangle ButtonRect = {
    .x = ui->position.x,
    .y = ui->position.y,
    .width = ui->textureSelected.width * ui->size,
    .height = ui->textureSelected.height * ui->size
  };

  Rectangle MouseRect = {
    .x = GetMousePosition().x,
    .y = GetMousePosition().y,
    .width = 4,
    .height = 4
  };

  if (CheckCollisionRecs(ButtonRect, MouseRect)) {
    ui->textureSelected = ui->textureHovered;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      SetState(_state);
    }
  } else {
    ui->textureSelected = ui->textureNormal;
  }
}

void UiButtonDraw(UiButton* ui) {
    DrawTextureEx(ui->textureSelected, ui->position, ui->rotation, ui->size, WHITE);
}