#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

class Ball
{
public:
    raylib::Vector2 position;
    raylib::Vector2 speed;
    float radius;

    void Draw()
    {
        position.DrawCircle(radius, raylib::Color::White());
    }

    void Update()
    {
        position += speed;
    }
};

raylib::Vector2 ballPosition{CENTER_X, CENTER_Y};
raylib::Vector2 rectanglePosition{10, CENTER_Y - (120 / 2)};
raylib::Vector2 rectangle2Position{SCREEN_WIDTH - (25 + 10), CENTER_Y - 60};
raylib::Vector2 linePosition{CENTER_X, 0};

Ball ball;

void Setup()
{
    ball.radius = 20;
    ball.position.x = CENTER_X;
    ball.position.y = CENTER_Y;
    ball.speed.x = 7;
    ball.speed.y = 7;
}

void Updater()
{
    ball.Update();
}

void Render()
{
    linePosition.DrawLine({CENTER_X, SCREEN_HEIGHT}, raylib::Color::White());
    ball.Draw();
    rectanglePosition.DrawRectangle({25, 120}, raylib::Color::White());
    rectangle2Position.DrawRectangle({25, 120}, raylib::Color::White());
}

int main()
{
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    window.SetTargetFPS(60);

    Setup();

    while (!window.ShouldClose())
    {
        Updater();

        while (window.Drawing())
            Render();
    }

    return 0;
}
