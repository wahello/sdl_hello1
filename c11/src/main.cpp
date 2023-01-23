#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "config.h"


const int WIDTH = 100;
const int HEIGHT = 100;

int x = 0;

void draw(SDL_Window * win, SDL_Surface *surface, SDL_Surface *img) {

    SDL_Rect src_rect = {0, 0, img->w, img->h};
    SDL_BlitSurface(img, &src_rect, surface, &src_rect);


    SDL_UpdateWindowSurface(win);
    
}

void event_loop(SDL_Window * win, SDL_Surface *surface, SDL_Surface *img) {

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        
        uint32_t begin = SDL_GetTicks();

        draw(win, surface, img);

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
        
        long current = SDL_GetTicks();
        long cost = current - begin;
        long  frame = 1000 / frame_rate;
        long delay = frame - cost;

        if (delay > 0) {
            SDL_Delay(delay);
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

    SDL_Surface *img = IMG_Load(img_path);
    SDL_Surface* surface = SDL_GetWindowSurface(win);

    event_loop(win, surface, img);

    SDL_FreeSurface(img);
    SDL_DestroyWindow(win);

    return 0;
}


