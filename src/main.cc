#include <iostream>

#include "drawEngine/drawEngine.hh"
#include "inputEngine/inputEngine.hh"

int main()

{
    drawEngine drawingEngine = drawEngine();
    drawingEngine.addDrawObject(drawingEngine.makeDrawObject("name", 0, 0, 100, 100, 0xFF, 0xFF, 0xFF));
    drawingEngine.addDrawObject(drawingEngine.makeDrawObject("name1", 100, 0, 100, 100, 0x00, 0xFF, 0xFF));
    drawingEngine.addDrawObject(drawingEngine.makeDrawObject("name2", 200, 0, 100, 100, 0xFF, 0x00, 0xFF));
    drawingEngine.addDrawObject(drawingEngine.makeDrawObject("name3", 300, 0, 100, 100, 0xFF, 0xFF, 0x00));

    SDL_Window* window = drawingEngine.getWindow();

    inputEngine inputsEngine = inputEngine(window);

    bool quit = false;
    while (quit == true) {
        inputsEngine.loop();
        drawingEngine.loop();
    }

    return 0;
}