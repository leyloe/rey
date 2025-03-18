#include "Window.hpp"

namespace gcs
{
    Window::Window(int width, int height, std::string_view title)
    {
        InitWindow(width, height, title.data());
    }

    Window::~Window()
    {
        CloseWindow();
    }

    bool Window::shouldClose()
    {
        return WindowShouldClose();
    }
}
