#include "inputEngine.hh"

#include <iostream>

// WIP

void callback1(const SDL_Event& event)
{
    SDL_Log(
        "%s:%d %s",
        __FUNCTION__,
        __LINE__,
        SDL_GetKeyName(event.key.keysym.sym));
}

InputEngine::InputEngine(SDL_Window* window)
{
    m_window = window;
}

void InputEngine::loop()
{
    if (m_inputCallbacks.empty()) {
        return;
    }
    for (std::size_t i { 0 }; i < m_inputCallbacks.size(); ++i) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            const auto it { m_inputCallbacks.find(e.type) };
            if (m_inputCallbacks.cend() == it) {
                continue;
            }
            const auto& callbacks { it->second };

            for (const auto& callback : callbacks) {
                callback(e);
            }
        }
    }
}

void InputEngine::addInputCallback(
    Uint32 eventType,
    const InputCbFuncT& callback)
{
    const auto it { m_inputCallbacks.find(eventType) };
    if (m_inputCallbacks.cend() == it) {
        m_inputCallbacks.try_emplace(
            eventType,
            std::vector<InputCbFuncT> { callback });
        return;
    }
    auto& callbacks { it->second };

    callbacks.push_back(callback);
}