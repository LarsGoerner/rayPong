// SPDX-License-Identifier: CC0-1.0

#ifndef RAYPONG_SRC_PADDLE_H_
#define RAYPONG_SRC_PADDLE_H_

#include <stdbool.h>

#include <raylib.h>

typedef struct Paddle {
        int x, y;
        int width, height;
        int speed;
        Color color;
} Paddle;

static inline void Paddle_draw(const Paddle * const paddle)
{
        DrawRectangle(paddle->x, paddle->y, 
                      paddle->width, paddle->height, 
                      paddle->color);
}

static inline void Paddle_update_player(Paddle * const p)
{
        if (IsKeyDown(KEY_UP) && p->y > 0) {
                p->y -= p->speed;
        } else if (IsKeyDown(KEY_DOWN) && p->y + p->height < GetScreenHeight()) {
                p->y += p->speed;
        }
}

static inline void Paddle_update_cpu(Paddle * const p, const Ball * b)
{
        if (p->y + p->height / 2 > b->y && p->y > 0) {
                p->y -= p->speed;
        } else if (p->y + p->height / 2 < b->y && p->y + p->height < GetScreenHeight()) {
                p->y += p->speed;
        }
}

#endif // RAYPONG_SRC_PADDLE_H_