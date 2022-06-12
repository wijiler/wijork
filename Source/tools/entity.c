#include"image.h"
typedef struct entity2D_T 
{
int posx;
int posy;
SDL_Texture * sprite;
} entity2D;
void drawEntity ( entity2D entity,SDL_Renderer * rend,int spritewidth,int spriteheight) 
{
drawImage(entity.sprite,rend,entity.posx,entity.posy,spritewidth,spriteheight);
}
