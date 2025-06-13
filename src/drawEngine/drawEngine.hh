#pragma once

#include <SDL.h>
#include <map>
#include <string>

struct DrawObject {
    SDL_Rect rect;
    SDL_Color color;
};

class DrawEngine final {
public:
    DrawEngine();
    ~DrawEngine();

    void loop();
    void addDrawObject(
        std::string&& name,
        DrawObject&& object);
    void editDrawObject(
        std::string&& name,
        SDL_Rect&& rect);
    void editDrawObject(
        std::string&& name,
        SDL_Color&& color);

    static bool isKeyPressed(const SDL_Event& event, const char* key);

    SDL_Window* getWindow();

private:
    int m_displayWidth;
    int m_displayHeight;
    int m_windowWidth;
    int m_windowHeight;
    int m_windowPosX;
    int m_windowPosY;
    std::map<std::string, DrawObject, std::less<>> m_drawObjects;

    SDL_DisplayMode m_displayMode;
    SDL_Window* m_window;
    SDL_Surface* m_screenSurface;
};
