#include"image.h"
typedef struct entity2D
{
float posx;
float posy;
SDL_Texture * sprite;
int width;
int height;
} entity2D;
void drawEntity ( entity2D entity,SDL_Renderer * rend) 
{
drawImage(entity.sprite,rend,entity.posx,entity.posy * -1,entity.width,entity.height);
}
