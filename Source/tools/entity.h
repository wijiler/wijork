#include"entity.c"
#define ENTITY
#ifndef ENTITY
typedef struct Entity2d_T entity2D;
void drawEntity ( entity2D entity,SDL_Renderer * rend,int spritewidth,int spriteheight);
#endif
