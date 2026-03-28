#pragma once
#include "stela.h"

#include <SDL3/SDL.h>

namespace Stela {
    class STELA_API Renderer {
    public:
        static void Init(SDL_Renderer* r);
        static SDL_Renderer* Get();

    private:
        static SDL_Renderer* renderer;
    };
}