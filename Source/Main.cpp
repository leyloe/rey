#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

class Ball
{
public:
    Ball(raylib::Vector2 position, float radius, float speed) : m_Position{position}, m_Radius{radius}, m_Speed{speed, speed}
    {
    }

    void Draw()
    {
        m_Position.DrawCircle(m_Radius, raylib::Color::White());
    }

    void Update()
    {
        m_Position += m_Speed;

        if (m_Position.y + m_Radius >= SCREEN_HEIGHT || m_Position.y - m_Radius <= 0)
            m_Speed.y *= -1;

        if (m_Position.x + m_Radius >= SCREEN_WIDTH || m_Position.x - m_Radius <= 0)
            m_Speed.x *= -1;
    }

private:
    raylib::Vector2 m_Position;
    raylib::Vector2 m_Speed;
    float m_Radius;
};

raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

raylib::Vector2 center{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
raylib::Vector2 ballPosition{center.x, center.y};
raylib::Vector2 rectanglePosition{10, center.y - (120 / 2)};
raylib::Vector2 rectangle2Position{SCREEN_WIDTH - (25 + 10), center.y - 60};
raylib::Vector2 linePosition{center.x, 0};

Ball ball{center, 20, 7};

void Setup()
{
    window.SetTargetFPS(60);
}

void Update()
{
    ball.Update();
}

void Render()
{
    window.ClearBackground(raylib::Color::Black());
    linePosition.DrawLine({center.x, SCREEN_HEIGHT}, raylib::Color::White());
    ball.Draw();
    rectanglePosition.DrawRectangle({25, 120}, raylib::Color::White());
    rectangle2Position.DrawRectangle({25, 120}, raylib::Color::White());
}

int main()
{
    Setup();

    while (!window.ShouldClose())
    {
        Update();

        while (window.Drawing())
            Render();
    }

    return 0;
}
