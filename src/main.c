// SPDX-License-Identifier: CC0-1.0

#include <raylib.h>

#include "GameField.h"
#include "Ball.h"
#include "Paddle.h"

GameField game_field;
Ball ball;
Paddle player;
Paddle cpu;

#define BG_COLOR        BLACK
#define FG_COLOR        WHITE

static unsigned player_score = 0;
static unsigned cpu_score = 0;

int main(void)
{
        InitWindow(1280, 800, "rayPong");
        SetTargetFPS(60);

        game_field.bg_color = BG_COLOR;
        game_field.fg_color = FG_COLOR;

        ball.radius = 20;
        ball.x = GetScreenWidth() / 2;
        ball.y = GetScreenHeight() / 2;
        ball.speed_x = 7;
        ball.speed_y = 7;
        ball.color = FG_COLOR;

        player.width = 24;
        player.height = 120;
        player.x = 10;
        player.y = GetScreenHeight() / 2 - player.height / 2;
        player.speed = 6;
        player.color = FG_COLOR;

        cpu.width = player.width;
        cpu.height = player.height;
        cpu.x = GetScreenWidth() - cpu.width - 10;
        cpu.y = GetScreenHeight() / 2 - cpu.height / 2;
        cpu.speed = 6;
        cpu.color = FG_COLOR;

        while (WindowShouldClose() == false) {
                // update elements
                Ball_update(&ball, &player_score, &cpu_score);
                Paddle_update_player(&player);
                Paddle_update_cpu(&cpu, &ball);

                // check collisions
                Vector2 ball_pos = { ball.x, ball.y };
                Rectangle player_rect = { player.x, player.y, player.width, player.height };
                Rectangle cpu_rect = { cpu.x, cpu.y, cpu.width, cpu.height };
                if (CheckCollisionCircleRec(ball_pos, ball.radius, player_rect) ||
                    CheckCollisionCircleRec(ball_pos, ball.radius, cpu_rect)) {
                        ball.speed_x = -ball.speed_x;
                }

                // draw
                BeginDrawing();
                GameField_draw(&game_field, &player_score, &cpu_score);
                Ball_draw(&ball);
                Paddle_draw(&player);
                Paddle_draw(&cpu);
                
                EndDrawing();
        }

        CloseWindow();
        return 0;
}