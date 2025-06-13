#include <iostream>

#include "drawEngine/drawEngine.hh"
#include "inputEngine/inputEngine.hh"

int main()

{
    auto drawEngine = DrawEngine();
    std::string object0Name = "0";
    SDL_Rect object0rect { 0, 150, 50, 50 };
    drawEngine.addDrawObject(
        std::string { object0Name },
        { //
            { object0rect },
            { 0xFF, 0xFF, 0xFF } });

    SDL_Window* window = drawEngine.getWindow();

    auto inputEngine = InputEngine(window);

    bool quit = false;
    inputEngine.addInputCallback(
        SDL_QUIT,
        [&quit]([[maybe_unused]] const SDL_Event& event) {
            quit = true;
        });
    inputEngine.addInputCallback(
        SDL_KEYDOWN,
        [&drawEngine, &object0Name, &object0rect](const SDL_Event& event) {
            if (DrawEngine::isKeyPressed(event, "W")) {
                object0rect.y = object0rect.y - 10;
                drawEngine.editDrawObject(
                    std::string { object0Name },
                    SDL_Rect { object0rect });
            }
        });
    inputEngine.addInputCallback(
        SDL_KEYDOWN,
        [&drawEngine, &object0Name, &object0rect](const SDL_Event& event) {
            if (DrawEngine::isKeyPressed(event, "A")) {
                object0rect.x = object0rect.x - 10;
                drawEngine.editDrawObject(
                    std::string { object0Name },
                    SDL_Rect { object0rect });
            }
        });
    inputEngine.addInputCallback(
        SDL_KEYDOWN,
        [&drawEngine, &object0Name, &object0rect](const SDL_Event& event) {
            if (DrawEngine::isKeyPressed(event, "S")) {
                object0rect.y = object0rect.y + 10;
                drawEngine.editDrawObject(
                    std::string { object0Name },
                    SDL_Rect { object0rect });
            }
        });
    inputEngine.addInputCallback(
        SDL_KEYDOWN,
        [&drawEngine, &object0Name, &object0rect](const SDL_Event& event) {
            if (DrawEngine::isKeyPressed(event, "D")) {
                object0rect.x = object0rect.x + 10;
                drawEngine.editDrawObject(
                    std::string { object0Name },
                    SDL_Rect { object0rect });
            }
        });
    while (quit == false) {
        inputEngine.loop();
        drawEngine.loop();
    }
    return 0;
}