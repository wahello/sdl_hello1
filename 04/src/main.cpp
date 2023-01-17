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

//Loads individual image
SDL_Surface* loadSurface( std::string path );


//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;


bool init() {
    
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    //Create window
    gWindow = SDL_CreateWindow("SDL tutorial 04", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);

    return true;
}

bool loadMedia() {

	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "assets/press.bmp" );
    if ( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT] == NULL ) {
		printf( "Failed to load up image!\n" );
        return false;
    }

	//Load up surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "assets/up.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load down image!\n" );
        return false;
	}

	//Load down surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "assets/down.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load down image!\n" );
        return false;
	}

	//Load left surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "assets/left.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n" );
        return false;
	}

	//Load right surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "assets/right.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n" );
        return false;
	}

    return true;
}

void close() {

	//Deallocate surfaces
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i ) {
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path ) {
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
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
                switch (e.key.keysym.sym) {
                case SDLK_UP: {
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                    break;
                }
                case SDLK_DOWN: {
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                    break;
                }
                case SDLK_LEFT: {
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                    break;
                }
                case SDLK_RIGHT: {
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                    break;
                }
                case SDLK_q: {
                    quit = true;
                    break;
                }
                default:
                    gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                    break;
                }
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
	    
        //Apply the image
    	SDL_BlitSurface( gCurrentSurface , NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );

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
