// SPDX-License-Identifier: CC0-1.0

#ifndef RAYPONG_SRC_BALL_H_
#define RAYPONG_SRC_BALL_H_

#include <raylib.h>

typedef struct Ball {
        int x, y;
        int speed_x, speed_y;
        int radius;
        Color color;
} Ball;

static inline void Ball_draw(const Ball * const b)
{
        DrawCircle(b->x, b->y, b->radius, b->color);
}

static inline void Ball_reset(Ball * const b)
{
        static const speed_mul[] = { -1, 1 };
        b->x = GetScreenWidth() / 2;
        b->y = GetScreenHeight() / 2;
        b->speed_x *= speed_mul[GetRandomValue(0, 1)];
        b->speed_y *= speed_mul[GetRandomValue(0, 1)];
}

static inline void Ball_update(Ball * const b, unsigned * const player_score,
                               unsigned * const cpu_score)
{
        // update position
        b->x += b->speed_x;
        b->y += b->speed_y;

        // check collition
        if (b->y + b->radius >= GetScreenHeight() ||
            b->y - b->radius <= 0) {
                b->speed_y = -b->speed_y;
        }

        if (b->x + b->radius >= GetScreenWidth()) {
                *player_score += 1;
                Ball_reset(b);
        } else if (b->x - b->radius <= 0) {
                *cpu_score += 1;
                Ball_reset(b);
        }
}

#endif // RAYPONG_SRC_BALL_H_