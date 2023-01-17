#ifndef __CONFIG_H_
#define __CONFIG_H_


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* image_path = "assets/x.bmp";

enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,

	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


#endif //!__CONFIG_H_
