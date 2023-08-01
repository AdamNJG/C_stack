#include <stdio.h>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL count not initialize!");
        return 1;
    }

    SDL_Window* window = NULL;
    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created!");
        return 1;
    }

    printf("window is running now!");
    
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

int WinMain(){
    int argc = 0;
    char** argv = NULL;

    main(argc, argv);
}