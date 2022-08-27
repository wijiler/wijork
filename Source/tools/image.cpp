#include"../global.h"
void unloadImage(SDL_Texture * texture) {
	SDL_DestroyTexture(texture);
}
SDL_Rect dstrect;
SDL_Rect srcrect;
int initImgSys() {
	int init = IMG_Init(IMG_INIT_PNG);
	if((init & IMG_INIT_PNG) != IMG_INIT_PNG) {
		printf("Couldnt init SDL2_image do you have it installed?");
	}
	return 0;
}
SDL_Surface *loadImage (char* filename) {

	SDL_Surface * image = IMG_Load(filename);
	if(!image) { printf("Could not load image because : %s\n",IMG_GetError()); EXIT_FAILURE; }
 
	return image;
}
SDL_Texture *createImageTexture(SDL_Surface * image,SDL_Renderer * rend) {
	SDL_Texture * texture = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	return texture;
}
int drawImage (SDL_Texture *texture,SDL_Renderer *rend,int posx,int posy,int width,int height) {
	dstrect.x = posx;
	dstrect.y= posy;
	dstrect.w = width;
	dstrect.h = height;
	SDL_RenderCopy(rend, texture, NULL, &dstrect);
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			unloadImage(texture);
			IMG_Quit();
		}
	}
	return 0;
}
