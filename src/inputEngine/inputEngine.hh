#pragma once

#include <SDL.h>
#include <functional>
#include <map>
#include <string>
#include <vector>

class InputEngine final {
public:
    using InputCbFuncT = std::function<void(const SDL_Event&)>;

    explicit InputEngine(SDL_Window* currentWindow);
    ~InputEngine() = default;
    void loop();
    void addInputCallback(
        Uint32 eventType,
        const InputCbFuncT& callback);

private:
    SDL_Window* m_window;
    std::map<Uint32, std::vector<InputCbFuncT>> m_inputCallbacks;
};