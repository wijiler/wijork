#include"global.h"
#include"tools/entity.h"
#include"tools/animation/animation.h"
#include"tools/audio/audio.h"
#include"tools/window.h"
static const int width = 800;
static const int height = 600;
int main (int argc, char **argv)
{
    /*SDL_Init(SDL_INIT_VIDEO);
    int init = IMG_Init(IMG_INIT_PNG);
    if((init & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Couldnt load images :P");
    }*/   
    // Create the window
    SDL_Window *window = createwindow("example",width,height,true);
    // renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
//  SDL_Surface * image = IMG_Load("funnyman.png");
//  if(!image) { printf("Could not load image because : %s\n",IMG_GetError()); }
//  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    // settings
/*  SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_SetWindowOpacity(window,1.0f);
*/
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);
   // create sprites
    SDL_Surface * funnyman_surface = loadImage("pins_1.png");//,*f1 = loadImage("animation_run/pins2.png"),*f2 = loadImage("animation_run/pins3.png"),*f3 = loadImage("animation_run/pins4.png"),*f4 = loadImage("animation_run/pins5.png");
    SDL_Texture * funnyman = createImageTexture(funnyman_surface,renderer);//,*pins1 = createImageTexture(f1,renderer),*pins2 = createImageTexture(f2,renderer),*pins3 = createImageTexture(f3,renderer),*pins4 = createImageTexture(f4,renderer);
    entity2D player;
    player.posx = 0;
    player.posy = 0;
    player.sprite = funnyman;
    player.height = 128;
    player.width = 128;
    animation_t run_anim;
    run_anim.images = {"animation_run/pins2.png","animation_run/pins3.png","animation_run/pins4.png","animation_run/pins5.png"};
    loadyoshit(run_anim,renderer);
    animator_t player_animator;
    player_animator.entity = player;
    /*animator_t player_animation; 
    player_animation.entity = player;
    player_animation.State = "idle";
    animation_t player_running;
    player_running.images = { pins1,pins2,pins3,pins4 }; 
    player_running.stateActivate = "running";
    */
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
    
    playAnimation(player_animator,run_anim,4);
    SDL_RenderClear(renderer);
//  SDL_RenderCopy(renderer, texture, NULL, NULL);
  drawImage(funnyman,renderer,0,12,100,100);
    const Uint8* state = SDL_GetKeyboardState(NULL);
//    player.posy -= 0.5f;
    /*	  if( state[SDL_SCANCODE_W]) {
		  player.posy += gravity(10.0f,-9.8,true) + speed;
    }
    */
   if( state[SDL_SCANCODE_Q] ) {
	   running = false;
   }
 /*  else if ( state[SDL_SCANCODE_S] ) {
	   player.posy -= 1 + speed;
   }
*/
   else if ( state[SDL_SCANCODE_A] ) {
	   player.posx -= 0.5f;
   }
   else if ( state[SDL_SCANCODE_D] ) {
	   player.posx += 0.5f;
   }   
  /* else if ( state[SDL_SCANCODE_SPACE] ) {
	   player.posy += 3;
   }*/
   else if ( state[SDL_SCANCODE_W] ) {
	   player.posy +=0.5f;
   }
   else if ( state[SDL_SCANCODE_S] ) {
	   player.posy -= 0.5f;
   }
   else if ( state[SDL_SCANCODE_P] ) {
	play_Audio("glados.mp3",false);
   }

  drawEntity(player,renderer);
       SDL_RenderPresent(renderer);

    }
    // release resources
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    drop_engine();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
