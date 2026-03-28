#include "Window/Window.h"

using namespace Stela;

int main() {
    Window window;
    Object object;

    auto mainWindow = window.Create("Stela", 800, 600);

    auto renderer = window.GetRenderer();

    SDL_Texture* rectTexture = object.LoadTexture("rectTexture.png");
    Object::Rect rect = {rectTexture, 0, 0, 100, 100, 255, 0, 0, 255};

    // FULLSCREEN BACKGROUND
    Object::Rect background = {nullptr, 0, 0, (float)window.width, (float)window.height, 100, 149, 237, 255};

    window.WindowLoop(
        mainWindow, 

        // Render
        [&]() {
        // Center rectangle
        rect.x = (window.width - rect.w) / 2.0f;
        rect.y = (window.height - rect.h) / 2.0f;

        // Update background
        background.w = (window.width);
        background.h = (window.height);

        // Draw background
        object.Draw(background);

        // Draw rect
        object.Draw(rect);
    },

    // Event
    [&](SDL_Event& e) {
        
    });

    window.Cleanup(mainWindow);

    return 0;
}