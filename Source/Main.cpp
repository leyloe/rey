#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

#define PLAYER_WIDTH 25
#define PLAYER_HEIGHT 120

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

class Paddle
{
public:
    Paddle(raylib::Vector2 position, raylib::Vector2 size, float speed) : m_Position{position}, m_Size{size}, m_Speed{speed}
    {
    }

    void Draw()
    {
        m_Position.DrawRectangle(m_Size, raylib::Color::White());
    }

    void Update()
    {
        if (raylib::Keyboard::IsKeyDown(KEY_UP))
            m_Position.y -= m_Speed;

        if (raylib::Keyboard::IsKeyDown(KEY_DOWN))
            m_Position.y += m_Speed;

        if (m_Position.y <= 0)
            m_Position.y = 0;

        if (m_Position.y + m_Size.y >= SCREEN_HEIGHT)
            m_Position.y = SCREEN_HEIGHT - m_Size.y;
    }

private:
    raylib::Vector2 m_Position;
    raylib::Vector2 m_Size;
    float m_Speed;
};

const raylib::Vector2 center{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

Ball ball{center, 20, 7};
Paddle player{{SCREEN_WIDTH - PLAYER_WIDTH - 10, center.y - PLAYER_HEIGHT / 2}, {PLAYER_WIDTH, PLAYER_HEIGHT}, 6};

void Setup()
{
    window.SetTargetFPS(60);
}

void Update()
{
    ball.Update();
    player.Update();
}

void Render()
{
    window.ClearBackground(raylib::Color::Black());
    DrawLine(center.x, 0, center.x, SCREEN_HEIGHT, raylib::Color::White());
    ball.Draw();
    player.Draw();
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
