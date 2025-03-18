#include "Window.hpp"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    gcs::Window window{screenWidth, screenHeight, "App"};

    Vector2 ballPos = {(float)screenWidth / 2, (float)screenHeight / 2};
    Vector2 sqaurePos = {(float)screenWidth / 2, (float)screenHeight / 2};

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