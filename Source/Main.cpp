#include "Window.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define WINDOW_TITLE "App"

int main(void)
{
    gcs::Window window = {SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE};

    Vector2 ballPos = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
    Vector2 sqaurePos = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

    SetTargetFPS(60);

    while (!window.shouldClose())
    {

        if (IsKeyDown(KEY_RIGHT))
            ballPos.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))
            ballPos.x -= 2.0f;
        if (IsKeyDown(KEY_UP))
            ballPos.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN))
            ballPos.y += 2.0f;

        sqaurePos = GetMousePosition();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(ballPos, 50, MAROON);

        DrawRectangleV(sqaurePos, {30, 30}, RED);

        EndDrawing();
    }

    return 0;
}