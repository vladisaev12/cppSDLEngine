#include <iostream>

#include "drawEngine.hh"

drawEngine::drawEngine()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
    }

    SDL_GetCurrentDisplayMode(0, &displayMode);

    displayWidth = displayMode.w;
    displayHeight = displayMode.h;
    windowWidth = displayWidth / 2;
    windowHeight = displayHeight / 2;
    windowPosX = displayWidth / 2 - windowWidth / 2;
    windowPosY = displayHeight / 2 - windowHeight / 2;

    window = SDL_CreateWindow("SDL_Test", windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }

    screenSurface = SDL_GetWindowSurface(window);
}

void drawEngine::loop()
{
    // SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    if (drawObjects.size() == 0) {
        return;
    }
    std::vector<std::string> names;
    for (int i = 0; i <= drawObjects.size() - 1; i++) {
        names.push_back(drawObjects[i].name);
        SDL_Rect* rect = new SDL_Rect;
        rect->x = drawObjects[i].pos[0];
        rect->y = drawObjects[i].pos[1];
        rect->h = drawObjects[i].size[0];
        rect->w = drawObjects[i].size[1];
        SDL_FillRect(screenSurface, rect, SDL_MapRGB(screenSurface->format, drawObjects[i].color[0], drawObjects[i].color[1], drawObjects[i].color[2]));
    }
    bool names_intersect = false;
    for (int i = 0; i <= names.size(); i++) {
        for (int j = i + 1; j < names.size(); j++) {
            if (names[j] == names[i])
                names_intersect = true;
        }
    }
    if (names_intersect == true) {
        std::cout << "Fatal Error: two drawObject names intersect, Exiting now!" << std::endl;
        delete this;
    }
    SDL_UpdateWindowSurface(window);
}

void drawEngine::addDrawObject(drawObject object)
{
    drawObjects.push_back(object);
}

drawObject drawEngine::makeDrawObject(std::string name, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b)
{
    drawObject object;
    object.name = name;
    object.pos[0] = x;
    object.pos[1] = y;
    object.size[0] = w;
    object.size[1] = h;
    object.color[0] = r;
    object.color[1] = g;
    object.color[2] = b;
    return object;
}

SDL_Window* drawEngine::getWindow()
{
    return window;
}

drawEngine::~drawEngine()
{
    SDL_Quit();
    SDL_DestroyWindow(window);
}