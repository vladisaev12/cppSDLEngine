#include "inputEngine.hh"

inputEngine::inputEngine(SDL_Window* currentWindow)
{
    window = currentWindow;
    // this->addInputCallback(inputCallback("quit", SDL_QUIT, SDL_Quit));
}

inputEngine::~inputEngine()
{
}

void inputEngine::loop()
{
    if (inputCallbacks.size() == 0) {
        return;
    }
    std::vector<std::string> names;
    for (int i = 0; i <= inputCallbacks.size() - 1; i++) {
        names.push_back(inputCallbacks[i].name);
        while (SDL_PollEvent(&e)) {
            for (int i = 0; i <= inputCallbacks.size() - 1; i++) {
                if (e.type == inputCallbacks[i].event) {
                    // inputCallbacks[i].callback();
                }
            }
        }
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
}

void addInputCallback(inputCallback object);
{
    inputCallbacks.push_back(object);
}