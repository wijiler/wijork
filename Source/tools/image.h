#pragma once
#include"image.cpp"
int drawImage (SDL_Texture *texture,SDL_Renderer *rend,int posx,int posy,int width,int height);
SDL_Surface *loadImage (char *filename);
SDL_Texture *createImageTexture(SDL_Surface * image,SDL_Renderer * rend);
int initImgSys ();
