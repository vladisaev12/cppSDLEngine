#include <SDL.h>

#include <string>
#include <vector>

struct drawObject {
    std::string name;
    int pos[2];
    int size[2];
    uint8_t color[3];
};

class drawEngine {
private:
    int displayWidth;
    int displayHeight;
    int windowWidth;
    int windowHeight;
    int windowPosX;
    int windowPosY;
    std::vector<drawObject> drawObjects;

    SDL_DisplayMode displayMode;
    SDL_Window* window;
    SDL_Surface* screenSurface;

public:
    drawEngine();
    ~drawEngine();
    void loop();
    void addDrawObject(drawObject object);
    drawObject makeDrawObject(std::string name, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b);
    SDL_Window* getWindow();
};
