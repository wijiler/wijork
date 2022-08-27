#include"../global.h"
// initializes sdl2 and SDL2_Image and returns an sdl window so you can pass it to your SDL_Renderer
SDL_Window* createwindow(char* title,int width,int height,bool initImage) {
SDL_Init(SDL_INIT_VIDEO);
if (initImage) {
int init = IMG_Init(IMG_INIT_PNG);
if((init & IMG_INIT_PNG) != IMG_INIT_PNG) {
	printf("SDL2_Image -> FATAL: could not initialize sdl2 image");
}
}
SDL_Window* window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
return window;
}
