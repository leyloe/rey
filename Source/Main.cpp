#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define WINDOW_TITLE "Pong"

int main(void)
{
    raylib::Window window(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    raylib::Color textColor = raylib::Color::LightGray();

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        /* stuff that runs before drawing i guess */

        while (window.Drawing())
        {
            /* drawing scope */
            window.ClearBackground(RAYWHITE);
            textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        } /* EndDrawing() */

        /* maybe do stuff when you're done drawing? */
    }

    return 0;
}