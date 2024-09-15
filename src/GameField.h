// SPDX-License-Identifier: CC0-1.0

#ifndef RAYPONG_SRC_GAMEFIELD_H_
#define RAYPONG_SRC_GAMEFIELD_H_

#include <raylib.h>

typedef struct GameField {
        Color bg_color;
        Color fg_color;
} GameField;

static inline void GameField_draw(const GameField * const gf, 
                                  const unsigned * const player_score,
                                  const unsigned * const cpu_score)
{
        ClearBackground(gf->bg_color);
        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, 
                 GetScreenHeight(), gf->fg_color);
        DrawText(TextFormat("%d", *player_score), GetScreenWidth() / 4, 20, 80,
                 gf->fg_color);
        DrawText(TextFormat("%d", *cpu_score), GetScreenWidth() / 4 * 3, 20, 80,
                 gf->fg_color);
}

#endif // RAYPONG_SRC_GAMEFIELD_H_