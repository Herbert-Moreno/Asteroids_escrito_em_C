#include <stdio.h>
#include <raylib.h>
#include <game.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            //game_draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}