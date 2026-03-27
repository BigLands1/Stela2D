#include "Window/Window.h"

using namespace Stela;

int main() {
    Window window;
    Object object;

    auto mainWindow = window.Create("Stela", 800, 600);

    Object::Rect rect = {0, 0, 100, 100, 255, 0, 0, 0};

    // FULLSCREEN BACKGROUND
    Object::Rect background = {0, 0, (float)window.width, (float)window.height, 100, 149, 237, 255};

    window.WindowLoop(mainWindow, [&](Object::Render* renderer) {
        // Center rectangle
        rect.x = (window.width - rect.w) / 2.0f;
        rect.y = (window.height - rect.h) / 2.0f;

        // Update background
        background.w = (window.width);
        background.h = (window.height);

        // Draw background
        object.Draw(background, renderer);

        // Draw rect
        object.Draw(rect, renderer);
    });

    window.Cleanup(mainWindow);

    return 0;
}