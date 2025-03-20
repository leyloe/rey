#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

raylib::Vector2 ballPosition{CENTER_X, CENTER_Y};
raylib::Vector2 rectanglePosition{10, CENTER_Y - (120 / 2)};
raylib::Vector2 rectangle2Position{SCREEN_WIDTH - (25 + 10), CENTER_Y - 60};
raylib::Vector2 linePosition{};

void render()
{
    ballPosition.DrawCircle(20, raylib::Color::White());
    rectanglePosition.DrawRectangle({25, 120}, raylib::Color::White());
    rectangle2Position.DrawRectangle({25, 120}, raylib::Color::White());
}

int main()
{
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    window.SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        while (window.Drawing())
            render();
    }

    return 0;
}