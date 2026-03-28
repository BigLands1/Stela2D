#include "Window/Window.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

using namespace Stela;

void SetupImGuiStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    // === Layout & Rounding (modern & clean) ===
    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.60f;
    style.WindowPadding = ImVec2(0.0f, 0.0f);
    style.WindowRounding = 10.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.ChildRounding = 8.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 10.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(6.0f, 6.0f);
    style.FrameRounding = 6.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 6.0f);
    style.ItemInnerSpacing = ImVec2(6.0f, 4.0f);
    style.CellPadding = ImVec2(6.0f, 4.0f);
    style.IndentSpacing = 22.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 12.0f;
    style.GrabRounding = 6.0f;
    style.TabRounding = 8.0f;
    style.TabBorderSize = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    // === Colors - Deep dark + Neon Green accent ===
    style.Colors[ImGuiCol_Text]                  = ImVec4(0.95f, 0.95f, 0.96f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);

    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.10f, 0.10f, 0.11f, 1.00f);   // Very deep background
    style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.12f, 0.12f, 0.13f, 1.00f);
    style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.12f, 0.12f, 0.13f, 0.98f);

    style.Colors[ImGuiCol_Border]                = ImVec4(0.25f, 0.25f, 0.28f, 0.60f);
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

    style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.18f, 0.18f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.22f, 0.65f, 0.30f, 0.60f);   // Soft green hover
    style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.25f, 0.80f, 0.35f, 0.85f);

    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.15f, 0.45f, 0.25f, 1.00f);   // Green-tinted active title
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.08f, 0.08f, 0.09f, 0.70f);

    style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.12f, 0.12f, 0.13f, 1.00f);

    style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.10f, 0.10f, 0.11f, 0.60f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.35f, 0.35f, 0.38f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.45f, 0.45f, 0.48f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.55f, 0.55f, 0.58f, 1.00f);

    // Primary accent: Vibrant Neon Green
    const ImVec4 accent          = ImVec4(0.15f, 0.95f, 0.45f, 1.00f);   // Main green
    const ImVec4 accentHover     = ImVec4(0.25f, 1.00f, 0.55f, 1.00f);
    const ImVec4 accentActive    = ImVec4(0.10f, 0.85f, 0.35f, 1.00f);

    style.Colors[ImGuiCol_CheckMark]             = accent;
    style.Colors[ImGuiCol_SliderGrab]            = accent;
    style.Colors[ImGuiCol_SliderGrabActive]      = accentHover;

    style.Colors[ImGuiCol_Button]                = ImVec4(0.18f, 0.55f, 0.30f, 0.60f);
    style.Colors[ImGuiCol_ButtonHovered]         = accentHover;
    style.Colors[ImGuiCol_ButtonActive]          = accentActive;

    style.Colors[ImGuiCol_Header]                = ImVec4(0.18f, 0.55f, 0.30f, 0.55f);
    style.Colors[ImGuiCol_HeaderHovered]         = accentHover;
    style.Colors[ImGuiCol_HeaderActive]          = accentActive;

    style.Colors[ImGuiCol_Separator]             = ImVec4(0.25f, 0.25f, 0.28f, 0.70f);
    style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.30f, 0.75f, 0.40f, 0.80f);
    style.Colors[ImGuiCol_SeparatorActive]       = accent;

    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.20f, 0.60f, 0.35f, 0.30f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = accentHover;
    style.Colors[ImGuiCol_ResizeGripActive]      = accentActive;

    style.Colors[ImGuiCol_Tab]                   = ImVec4(0.15f, 0.18f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_TabHovered]            = accentHover;
    style.Colors[ImGuiCol_TabActive]             = ImVec4(0.20f, 0.65f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.12f, 0.12f, 0.13f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.18f, 0.45f, 0.28f, 1.00f);

    style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.60f, 0.80f, 0.40f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = accentHover;
    style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.80f, 0.30f, 1.00f);

    style.Colors[ImGuiCol_TableHeaderBg]         = ImVec4(0.15f, 0.15f, 0.17f, 1.00f);
    style.Colors[ImGuiCol_TableBorderStrong]     = ImVec4(0.28f, 0.28f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_TableBorderLight]      = ImVec4(0.22f, 0.22f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_TableRowBg]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TableRowBgAlt]         = ImVec4(1.00f, 1.00f, 1.00f, 0.04f);

    style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.25f, 0.85f, 0.45f, 0.40f);
    style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.95f, 0.90f, 0.20f, 0.90f);

    style.Colors[ImGuiCol_NavHighlight]          = accent;
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.00f, 0.00f, 0.00f, 0.65f);
}

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

    SetupImGuiStyle();

    int viewportWidth;
    int viewportHeight;

    std::vector<Object::Rect> objects;
    int selectedIndex = -1;

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

        ImGui::Begin("Objects");

        for (int i = 0; i < objects.size(); i++) {
            ImGui::PushID(i);

            bool isSelected = (selectedIndex == i);

            if (ImGui::Selectable(objects[i].name.c_str(), isSelected)) {
                selectedIndex = i;
            }

            ImGui::PopID();
        }

        if (ImGui::Button("Create Object")) {
            objects.push_back({
                nullptr,
                100, 100, 50, 50,
                255, 0, 0, 255,
                "New Object"
            });
        }

        ImGui::End();

        ImGui::Begin("Inspector");

        static char buffer[128] = "";

        if (selectedIndex != -1) {
            auto& obj = objects[selectedIndex];

            // Sync buffer only when selection changes
            static int lastSelected = -1;
            if (lastSelected != selectedIndex) {
                strncpy(buffer, obj.name.c_str(), sizeof(buffer));
                lastSelected = selectedIndex;
            }

            if (ImGui::InputText("Name", buffer, sizeof(buffer))) {
                obj.name = buffer;
            }

            ImGui::Separator();

            // Transform
            ImGui::DragFloat2("Position", &obj.x, 1.0f);
            ImGui::DragFloat2("Size", &obj.w, 1.0f);

            // Color
            float color[4] = {
                obj.r / 255.0f,
                obj.g / 255.0f,
                obj.b / 255.0f,
                obj.a / 255.0f
            };

            if (ImGui::ColorEdit4("Color", color)) {
                obj.r = (int)(color[0] * 255);
                obj.g = (int)(color[1] * 255);
                obj.b = (int)(color[2] * 255);
                obj.a = (int)(color[3] * 255);
            }

            ImGui::Separator();

            // Delete
            if (ImGui::Button("Delete Object")) {
                objects.erase(objects.begin() + selectedIndex);
                selectedIndex = -1;
            }

            if (ImGui::Button("Add Component")) {
                ImGui::OpenPopup("AddComponentPopup");
            }

            if (ImGui::BeginPopup("AddComponentPopup")) {

                if (ImGui::MenuItem("Texture")) {
                    if (!obj.textureComp) {
                        obj.textureComp = new Object::TextureComponent();
                    }
                }

                ImGui::EndPopup();
            }

            if (obj.textureComp) {
                ImGui::Separator();
                ImGui::Text("Texture Component");

                auto& tex = obj.textureComp;

                ImGui::Checkbox("Active", &tex->active);

                static char pathBuffer[256] = "";

                static int lastSelectedTex = -1;
                if (lastSelectedTex != selectedIndex) {
                    strncpy(pathBuffer, tex->path.c_str(), sizeof(pathBuffer));
                    lastSelectedTex = selectedIndex;
                }

                if (ImGui::InputText("Path", pathBuffer, sizeof(pathBuffer))) {
                    tex->path = pathBuffer;
                }

                if (ImGui::Button("Load Texture")) {
                    tex->texture = object.LoadTexture(tex->path.c_str());
                }

                if (ImGui::Button("Remove Component")) {
                    delete obj.textureComp;
                    obj.textureComp = nullptr;
                }
            }
        }
        else {
            ImGui::Text("No object selected");
        }

        ImGui::End();

        SDL_SetRenderTarget(renderer, viewportTexture);

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (auto& obj : objects) {
            if (obj.textureComp && obj.textureComp->active && obj.textureComp->texture) {
                // draw texture version
                Object::Rect textured = obj;
                textured.texture = obj.textureComp->texture;
                object.Draw(textured);
            } else {
                // fallback to color
                object.Draw(obj);
            }
        }

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