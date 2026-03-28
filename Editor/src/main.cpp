#include "Window/Window.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

using namespace Stela;

int main() {
    Window window;
    Object object;

    auto mainWindow = window.Create("Stela", 800, 600);

    auto renderer = window.GetRenderer();

    SDL_Texture* viewportTexture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    window.width,
    window.height
    );

    SDL_SetTextureBlendMode(viewportTexture, SDL_BLENDMODE_BLEND);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup backend
    ImGui_ImplSDL3_InitForSDLRenderer(mainWindow, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    int viewportWidth;
    int viewportHeight;

    SDL_Texture* rectTexture = object.LoadTexture("rectTexture.png");
    Object::Rect rect = {nullptr, 0, 0, 100, 100, 255, 0, 0, 255};

    // FULLSCREEN BACKGROUND
    Object::Rect background = {nullptr, 0, 0, (float)window.width, (float)window.height, 100, 149, 237, 255};

    window.WindowLoop(
        mainWindow, 

        // Render
        [&]() {

        // Start ImGui frame
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());

        // Show Demo window
        ImGui::ShowDemoWindow();

        ImGui::Begin("Viewport");

        // Get the available space inside ImGui window
        ImVec2 viewportSize = ImGui::GetContentRegionAvail();

        // Make sure the texture matches the new size
        if (viewportSize.x != viewportWidth || viewportSize.y != viewportHeight) {
            viewportWidth = (int)viewportSize.x;
            viewportHeight = (int)viewportSize.y;

        if (viewportTexture) SDL_DestroyTexture(viewportTexture);

            viewportTexture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            viewportWidth,
            viewportHeight
            );

            SDL_SetTextureBlendMode(viewportTexture, SDL_BLENDMODE_BLEND);
        }

        ImGui::Image((ImTextureID)(intptr_t)viewportTexture, viewportSize);

        ImGui::End();


        // Center rectangle
        rect.x = (viewportWidth - rect.w) / 2.0f;
        rect.y = (viewportHeight - rect.h) / 2.0f;

        // Update background
        background.w = (viewportWidth);
        background.h = (viewportHeight);

        SDL_SetRenderTarget(renderer, viewportTexture);

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw background
        object.Draw(background);

        // Draw rect
        object.Draw(rect);

        SDL_SetRenderTarget(renderer, nullptr);

        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    },

    // Event
    [&](SDL_Event& e) {
        ImGui_ImplSDL3_ProcessEvent(&e);
    });


    ImGui_ImplSDL3_Shutdown();
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui::DestroyContext();
    window.Cleanup(mainWindow);

    return 0;
}