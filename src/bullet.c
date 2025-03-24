#include <bullet.h>
#include <math.h>
#include <raymath.h>

void InitBullet(Bullet *bullet, const char *texturapath) {
    bullet->active = false;
    bullet->position = (Vector2){0, 0};
    bullet->fireDir = 0.0f;
    bullet->speed = 6.5f;
    bullet->texture = LoadTexture(texturapath);
    bullet->color = WHITE;
}

void BulletDraw(Bullet bullets[], int MAX_BULLETS) {
  for (int b = 0; b < MAX_BULLETS; b++) {
    if (bullets[b].active) {
      DrawTextureEx(bullets[b].texture, bullets[b].position, bullets[b].fireDir, 1.2, bullets[b].color);
   	}
  }
}

void BulletUpdate(Bullet bullets[], int MAX_BULLETS) {
// Atualiza balas
    for (int b = 0; b < MAX_BULLETS; b++) {
        if (bullets[b].active) {
            bullets[b].position.x -= cosf((bullets[b].fireDir + 90.0f) * DEG2RAD) * bullets[b].speed;
            bullets[b].position.y -= sinf((bullets[b].fireDir + 90.0f) * DEG2RAD) * bullets[b].speed;

            // Desativa balas que saem da tela
            if (bullets[b].position.x < -5 || bullets[b].position.x > GetScreenWidth() + 5 ||
                bullets[b].position.y < -5 || bullets[b].position.y > GetScreenHeight() + 5) {
                bullets[b].fireDir = 0.0f;
                bullets[b].active = false;
            };
        }
    }
}

void UnloadBulletTexture(Bullet bullets[], int MAX_BULLETS) {
  for (int b = 0; b < MAX_BULLETS; b++) {
    UnloadTexture(bullets[b].texture);
  }
}

void BulletShoot(Player *player, Bullet bullets[], int MAX_BULLETS) {
  for (int b = 0; b < MAX_BULLETS; b++) {
    if (!bullets[b].active) {
      // Configura bala
      bullets[b].position = player->position;
      bullets[b].fireDir = player->rotation;
      bullets[b].active = true;
      break;
    }
  }
}

void ResetBullets(Bullet bullets[], int MAX_BULLETS) {
  for (int b = 0; b < MAX_BULLETS; b++) {
    bullets[b].active = false;
    bullets[b].position = (Vector2){0, 0};
  }
}