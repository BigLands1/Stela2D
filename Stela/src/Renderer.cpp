#include "Renderer.h"

namespace Stela {
    SDL_Renderer* Renderer::renderer = nullptr;

    void Renderer::Init(SDL_Renderer* r) {
        renderer = r;
    }

    SDL_Renderer* Renderer::Get() {
        return renderer;
    }
}