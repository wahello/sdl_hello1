#include <stdio.h>
#include <SDL2/SDL.h>


#include "config.h"


const int WIDTH = 100;
const int HEIGHT = 100;

int x = 0;

void draw(SDL_Window * win, SDL_Surface *surface) {
    x ++;

    SDL_Rect r = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_FillRect(surface, &r, 0xffffffff); // ARGB 


    SDL_Rect rr = {x, 0, 100, 100};
    SDL_FillRect(surface, &rr, 0xffff0000); // ARGB 
    SDL_UpdateWindowSurface(win);
    
}

void event_loop(SDL_Window * win, SDL_Surface *surface) {

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        
        uint32_t begin = SDL_GetTicks();

        draw(win, surface);

        while (SDL_PollEvent(&e)) {
            /* code */
            switch (e.type) {
            case SDL_MOUSEBUTTONDOWN: {
                // quit = true;

                break;
            }
            case SDL_MOUSEBUTTONUP: {

                break;
            }
            case SDL_KEYDOWN: {
                // quit = true;

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
        
        uint32_t current = SDL_GetTicks();
        uint32_t cost = current - begin;
        uint32_t  frame = 1000 / frame_rate;
        uint32_t delay = frame - cost;

        if (delay > 0) {
            SDL_Delay(20);
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

    event_loop(win, surface);

    SDL_DestroyWindow(win);

    return 0;
}


