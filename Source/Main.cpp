#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

int main()
{
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    raylib::Vector2 ballPosition(CENTER_X, CENTER_Y);
    raylib::Vector2 rectanglePosition(0, 0);

    window.SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        while (window.Drawing())
        {
            ballPosition.DrawCircle(40, raylib::Color::White());
            rectanglePosition.DrawRectangle({25, 120}, raylib::Color::White());
        }
    }

    return 0;
}