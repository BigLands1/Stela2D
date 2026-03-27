#include "Window/Window.h"

int main() {
    Stela::Window window;

    auto mainWindow = window.Create("Stela", 800, 600);

    SDL_FRect rect = {0, 0, 100, 100};

    window.WindowLoop(mainWindow, [&](SDL_Renderer* renderer) {
        int w, h;
        SDL_GetWindowSize(mainWindow, &w, &h);

        // FULLSCREEN BACKGROUND
        SDL_FRect background = {0, 0, (float)w, (float)h};

        // Center rectangle
        rect.x = (w - rect.w) / 2.0f;
        rect.y = (h - rect.h) / 2.0f;

        // Draw background
        SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
        SDL_RenderFillRect(renderer, &background);

        // Draw rect
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect);
    });

    window.Cleanup(mainWindow);

    return 0;
}