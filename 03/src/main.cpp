#include <stdio.h>

#include <SDL2/SDL.h>

#include "config.h"


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gXOut = NULL;


bool init() {
    
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    //Create window
    gWindow = SDL_CreateWindow("SDL tutorial 02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);

    return true;
}

bool loadMedia() {

	gXOut = SDL_LoadBMP( "assets/hello_world.bmp" );
	if( gXOut == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "assets/hello_world.bmp", SDL_GetError() );
        return false;
    } 

    return true;
}

void close() {

    SDL_FreeSurface( gXOut );
    gXOut = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

void event_loop() {

    SDL_Event e;
    bool quit = false;
    while (!quit) {

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

int main(int argc, char const* argv[]) {
    
    if (!init()) {
        return -1;
    }

    if (!loadMedia()) {
        return -1;
    }


    event_loop();
    
    close();

    return 0;
}
