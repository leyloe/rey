#pragma once

#include "raylib.h"
#include <string_view>

namespace gcs
{
    class Window
    {
    private:
    public:
        Window(int width, int height, std::string_view title);
        ~Window();

        bool shouldClose();
    };

}