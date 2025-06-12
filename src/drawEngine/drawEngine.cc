#include <iostream>

#include "drawEngine.hh"

DrawEngine::DrawEngine()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;
    }

    SDL_GetCurrentDisplayMode(0, &m_displayMode);

    m_displayWidth = m_displayMode.w;
    m_displayHeight = m_displayMode.h;
    m_windowWidth = m_displayWidth / 2;
    m_windowHeight = m_displayHeight / 2;
    m_windowPosX = m_displayWidth / 2 - m_windowWidth / 2;
    m_windowPosY = m_displayHeight / 2 - m_windowHeight / 2;

    m_window = SDL_CreateWindow("SDL_Test", m_windowPosX, m_windowPosY, m_windowWidth, m_windowHeight, SDL_WINDOW_OPENGL);
    if (m_window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }

    m_screenSurface = SDL_GetWindowSurface(m_window);
}

void DrawEngine::loop()
{
    SDL_FillRect(m_screenSurface, nullptr, SDL_MapRGB(m_screenSurface->format, 0x00, 0x00, 0x00));
    if (m_drawObjects.empty()) {
        return;
    }
    for (const auto& [_, currentDrawObject] : m_drawObjects) {
        SDL_FillRect(
            m_screenSurface,
            &currentDrawObject.rect,
            SDL_MapRGB(
                m_screenSurface->format,
                currentDrawObject.color.r,
                currentDrawObject.color.g,
                currentDrawObject.color.b));
    }
    SDL_UpdateWindowSurface(m_window);
}

void DrawEngine::addDrawObject(
    std::string&& name,
    DrawObject&& object)
{
    m_drawObjects.try_emplace(std::move(name), std::move(object));
}

void DrawEngine::editDrawObject(
    std::string&& name,
    SDL_Rect&& rect)
{
    m_drawObjects[std::move(name)].rect = std::move(rect);
}
void DrawEngine::editDrawObject(
    std::string&& name,
    SDL_Color&& color)
{
    m_drawObjects[std::move(name)].color = std::move(color);
}

bool DrawEngine::isKeyPressed(const SDL_Event& event, const char* key)
{
    return event.key.keysym.sym == SDL_GetKeyFromName(key);
}

SDL_Window* DrawEngine::getWindow()
{
    return m_window;
}

DrawEngine::~DrawEngine()
{
    SDL_Quit();
    SDL_DestroyWindow(m_window);
}