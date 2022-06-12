#include<SDL2/SDL.h>
#include<stdbool.h>
SDL_Event event;
int getKeyPressed() {
	SDL_Keycode key;
	while( SDL_PollEvent( &event ) ) {
		switch(event.type)
		{
			case SDL_KEYDOWN:
				key = event.key.keysym.sym;
				break;
			default:
				break;
		}
	}
	return key;
}
bool hasKeyPressed() 
{
	bool keypress = false;
	while ( SDL_PollEvent ( &event ) ) {
		switch(event.type) 
		{
		 case SDL_KEYDOWN:
		 	keypress = true; 
			break;
		case SDL_KEYUP:
			keypress = false;
			break;
		default:
			keypress = false;
			break;
		}
	}
	return keypress;
}
