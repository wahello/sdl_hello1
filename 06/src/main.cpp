#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>

#include "config.h"


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gPNGSurface = NULL;

bool init() {
    
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    //Create window
    gWindow = SDL_CreateWindow("SDL tutorial 05", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);

    return true;
}

bool loadMedia() {

	gPNGSurface = loadSurface( image_path );
	if( gPNGSurface == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "assets/hello_world.bmp", SDL_GetError() );
        return false;
    } 

    return true;
}

void close() {

    SDL_FreeSurface( gPNGSurface );
    gPNGSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path ) {

	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if (loadedSurface == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return NULL;
    } 
	//Convert surface to screen format
	optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
    if( optimizedSurface == NULL ) {
		printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    
    return optimizedSurface;
}

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

    	SDL_BlitSurface( gStretchedSurface, NULL, gScreenSurface, NULL );

	    SDL_UpdateWindowSurface( gWindow );
    }
}

int main(int argc, char const* argv[]) {

    /* code */

    if ( !init() ) {

        return -1;
    } 
    
    int s = loadMedia();

    if (!s) {
        return -2;
    }

    event_loop();
    
    close();

    return 0;
}
