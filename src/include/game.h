#ifndef GAME_H
#define GAME_H

typedef enum GameState {
    Menu,
    Game,
    GameOver,
} GameState;

void GameInit(void);
void GameUpdate(void);
void GameDraw(void);
void SetState(GameState _state);
void ChangeScore(int _increment);

#endif //GAME_H
