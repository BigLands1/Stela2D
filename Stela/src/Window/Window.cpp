#include "Window/Window.h"

namespace Stela {
    SDL_Window* Window::Create(const char * title, int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_SetHint(SDL_HINT_RENDER_DRIVER, "direct3d12,metal,vulkan,direct3d11,opengl");

        SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);

        if (window == NULL) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could Not Create Window %s\n", SDL_GetError());
            return nullptr;
        }

        Window::width = width;

        Window::height = height;

        return window;
    }

    void Window::WindowLoop(SDL_Window* window, std::function<void(SDL_Renderer*)> renderFunc) {
        SDL_Event e;
        bool bQuit = false;

        while (!bQuit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_EVENT_QUIT) {
                    bQuit = true;
                }

                if (e.type == SDL_EVENT_WINDOW_RESIZED) {
                    width = e.window.data1;
                    height = e.window.data2;
                }
            }

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);

            // Call user-defined render code
            renderFunc(renderer);

            // Present
            SDL_RenderPresent(renderer);

            SDL_Delay(16);
        }
    }

    void Window::Cleanup(SDL_Window* window) {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }

        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        SDL_Quit();
    }

    void Object::Draw(Rect object, SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, object.r, object.b, object.g, object.a);
        SDL_FRect newObject = {object.x, object.y, object.w, object.h};
        SDL_RenderFillRect(renderer, &newObject);
    }
}