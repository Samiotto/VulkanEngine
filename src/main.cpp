#include <SDL.h>
#include <iostream>


int main(int argc, char *argv[]) {
    std::cout << "Vulkan Engine starting up ...\n";
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Vulkan Engine Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
        );

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 2;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        // do rendering stuff and things

        SDL_Delay(10);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}