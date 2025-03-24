#include <raylib.h>
#include <bullet.h>
#include <asteroid.h>
#include <game.h>
#include "raymath.h"

void AsteroidInit(Asteroid *asteroid, const char *texturapath, Player *player) {
    asteroid->active = false;
    asteroid->texture = LoadTexture(texturapath);
    asteroid->position = (Vector2){0.0f, 0.0f};
    asteroid->velocityDir = (Vector2){(float)GetRandomValue((int)-player->position.x, (int)player->position.x), (float)GetRandomValue((int)-player->position.y, (int)player->position.y)};
    asteroid->scale = GetRandomValue(2, 4);
    asteroid->src = (Rectangle){0.0f, 0.0f, (float)asteroid->texture.width, (float)asteroid->texture.width};
    asteroid->dest = (Rectangle){asteroid->position.x, asteroid->position.y, (float)(asteroid->texture.width * asteroid->scale), (float)(asteroid->texture.height * asteroid->scale)};
    asteroid->origin = (Vector2){(float)(asteroid->texture.width * asteroid->scale)/2, (float)(asteroid->texture.height * asteroid->scale)/2};
}

void AsteroidUpdate(Asteroid asteroids[], int MAX_ASTEROIDS, Bullet bullets[], int MAX_BULLETS, Player *player) {
    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        if (!asteroids[i].active) {
            continue;
        }
        asteroids[i].position = Vector2Add(asteroids[i].position,
        Vector2Scale(asteroids[i].velocityDir, .2f * GetFrameTime()));

        asteroids[i].dest = (Rectangle){asteroids[i].position.x, asteroids[i].position.y, (float)(asteroids[i].texture.width * asteroids[i].scale), (float)(asteroids[i].texture.height * asteroids[i].scale)};

        asteroids[i].rotation += 0.5f;
    }

    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        if (asteroids[i].active) {
            if (asteroids[i].position.x >= GetScreenWidth() + 150 || asteroids[i].position.y >= GetScreenHeight() + 150 || asteroids[i].position.x <= - 150 || asteroids[i].position.y <= -150) {
                asteroids[i].active = false;
            }
        } else {
            break;
        }
    }

    for (int a = 0; a < MAX_ASTEROIDS; a++) {
        for (int b = 0; b < MAX_BULLETS; b++) {
            if (asteroids[a].active) {
                if (bullets[b].active) {
                    if (CheckCollisionCircles(asteroids[a].position,
                        (float)(asteroids[a].texture.width * asteroids[a].scale)/2.0f,
                        bullets[b].position, (float)bullets[b].texture.width/2)) {
                        asteroids[a].active = false;
                        bullets[b].active = false;
                        ChangeScore(GetRandomValue(50, 125));
                    }
                }
            }
        }
    }

    for (int a = 0; a < MAX_ASTEROIDS; a++) {
        if (asteroids[a].active) {
            if (player->active) {
                if (CheckCollisionCircles(asteroids[a].position,
                    (float)(asteroids[a].texture.width * asteroids[a].scale)/2.0f,
                    player->position, (float)player->texture.width)) {
                    asteroids[a].active = false;
                    player->active = false;
                    SetState((GameState){GameOver});
                }
            }
        }
    }
}

void AsteroidDraw(Asteroid asteroids[], int MAX_ASTEROIDS) {
    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        if (asteroids[i].active) {
            DrawTexturePro(asteroids[i].texture, asteroids[i].src, asteroids[i].dest, asteroids[i].origin, asteroids[i].rotation, WHITE);
        }
    }
}

void GetAsteroidSpawn(Asteroid *asteroid) {
    Vector2 SpawnPos;

    if (asteroid->velocityDir.x >= 1) {
        SpawnPos.x = -10;
    } else {
        SpawnPos.x = (float)GetScreenWidth() + 10;
    }

    if (asteroid->velocityDir.y >= 1) {
        SpawnPos.y = (float)GetRandomValue(-10, GetScreenHeight()/2);
    } else {
        SpawnPos.y = (float)GetRandomValue(GetScreenHeight()/2, GetScreenWidth() + 10);
    }
    asteroid->position = SpawnPos;
}

void UnloadAsteroidsTexture(Asteroid asteroid[], int MAX_ASTEROIDS) {
    for (int a = 0; a < MAX_ASTEROIDS; a++) {
        UnloadTexture(asteroid[a].texture);
    }
}

void CreateAsteroid(Asteroid asteroids[], int MAX_ASTEROIDS) {
    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        int shouldSpawn = GetRandomValue(0, 1);
        if (shouldSpawn == 1 && !asteroids[i].active) {
            GetAsteroidSpawn(&asteroids[i]);
            asteroids[i].active = true;
            break;
        }
    }
}

void ResetAsteroids(Asteroid asteroids[], int MAX_ASTEROIDS, Player *player) {
    for (int i = 0; i < MAX_ASTEROIDS; i++) {
        asteroids[i].active = false;
        asteroids[i].position = (Vector2){0.0f, 0.0f};
        asteroids[i].velocityDir = (Vector2){(float)GetRandomValue((int)-player->position.x, (int)player->position.x), (float)GetRandomValue((int)-player->position.y, (int)player->position.y)};
        asteroids[i].scale = GetRandomValue(2, 4);
        asteroids[i].origin = (Vector2){(float)(asteroids[i].texture.width * asteroids[i].scale)/2, (float)(asteroids[i].texture.height * asteroids[i].scale)/2};
    }
}
