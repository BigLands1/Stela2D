#pragma once

#include "stela.h"
#include "Renderer.h"

#include "SDL3/SDL.h"
#include <SDL3_image/SDL_image.h>
#include <functional>

namespace Stela {
    class STELA_API Window {
        public:
            SDL_Window* Create(const char * name, int width, int height);
            void WindowLoop(SDL_Window* window, std::function<void()> renderFunc);
            void Cleanup(SDL_Window* window);
            SDL_Renderer* GetRenderer() const;

            int width;
            int height;

        private:
            SDL_Window *window;
            SDL_Renderer *renderer;
    };

    class STELA_API Object {
        public:
            SDL_Texture* LoadTexture(const char* path);
            struct Rect {SDL_Texture* texture; float x; float y; float w; float h; Uint8 r; Uint8 g; Uint8 b; Uint8 a;};
            using Render = SDL_Renderer;
            void Draw(Rect object);
        };
}