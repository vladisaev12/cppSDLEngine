#include <SDL.h>

#include <bits/stdc++.h>
#include <string>
#include <vector>

struct inputCallback {
    std::string name;
    Uint32 event;
    // std::function callback;
};

class inputEngine {
private:
    std::vector<inputCallback> inputCallbacks;
    SDL_Event e;
    SDL_Window* window;

public:
    inputEngine(SDL_Window* currentWindow);
    ~inputEngine();
    void loop();
    void addInputCallback(inputCallback object);
};
