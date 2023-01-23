#include <stdio.h>
#include <SDL2/SDL.h>


#include "config.h"


const int WIDTH = 100;
const int HEIGHT = 100;


void event_loop() {

    SDL_Event e;
    bool quit = false;
    while (!quit) {

        while (SDL_PollEvent(&e)) {
            /* code */
            switch (e.type) {
            case SDL_MOUSEBUTTONDOWN: {
                quit = true;

                break;
            }
            case SDL_MOUSEBUTTONUP: {

                break;
            }
            case SDL_KEYDOWN: {
                quit = true;

                break;
            }
            case SDL_QUIT: {
                quit = true;
                break;
            }
            default:
                break;
            }

        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Can not init video, %s", SDL_GetError());
        
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (win == NULL) {
        SDL_Log("Can not create window, %s", SDL_GetError());
        return 2;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(win);
    SDL_Rect r = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_FillRect(surface, &r, 0xffffffff); // ARGB 
    SDL_UpdateWindowSurface(win);

    SDL_Rect rr = {0, 0, 100, 100};
    SDL_FillRect(surface, &rr, 0xffff0000); // ARGB 
    SDL_UpdateWindowSurface(win);

    ((uint32_t *)(surface->pixels))[SCREEN_WIDTH * 50 + 50] = 0xff0000ff;

    for (int i = 0; i < 100; ++i) {
        ((uint32_t *)(surface->pixels))[SCREEN_WIDTH * 50 + 55 + i] = 0xff0000ff;

    }

    SDL_UpdateWindowSurface(win);
    
    event_loop();

    SDL_DestroyWindow(win);

    return 0;
}


