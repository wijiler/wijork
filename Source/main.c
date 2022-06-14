#include"global.h"
#include"tools/entity.h"
static const int width = 800;
static const int height = 600;
int main (int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    int init = IMG_Init(IMG_INIT_PNG);
    if((init & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Couldnt load images :P");
    }   
    // Create the window
    SDL_Window *window = SDL_CreateWindow("Ferengine",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    // renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
//  SDL_Surface * image = IMG_Load("funnyman.png");
//  if(!image) { printf("Could not load image because : %s\n",IMG_GetError()); }
//  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    // settings
/*  SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_SetWindowOpacity(window,1.0f);
*/
   // create sprites
    SDL_Surface * funnyman_surface = loadImage("funnyman.png");
    SDL_Texture * funnyman = createImageTexture(funnyman_surface,renderer);
    entity2D player;
    player.posx = 33;
    player.posy = 0;
    player.sprite = funnyman;
    int speed = 100;
    
    // loop 
    bool running = true;
    SDL_Event event;
    while(running) 
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }   
    SDL_RenderClear(renderer);
//  SDL_RenderCopy(renderer, texture, NULL, NULL);
  drawImage(funnyman,renderer,0,12,100,100);
  const Uint8* state = SDL_GetKeyboardState(NULL);
	  if( state[SDL_SCANCODE_W]) {
		  player.posy += 1 * speed;
    }
   else if( state[SDL_SCANCODE_Q] ) {
   }
  drawEntity(player,renderer,100,100);
       SDL_RenderPresent(renderer);

    }
    // release resources
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
