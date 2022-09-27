#include"../../global.h"	
#include"../entity.h"
#include<chrono>
#include<thread>
#include<future>
using namespace std;
// TODO: make the animation accept mp4 format as well
string State;
typedef struct {
	vector<char*> images;	
	string stateActivate;

}animation_t;
typedef struct {
	entity2D entity;
}animator_t;
// NOTE: do not use this function under any circumstances as it will pause the game,also this code fucking sucks
void playanimation_interrupting (animator_t animator,animation_t animation,unsigned int fps,SDL_Renderer* rend) {
SDL_Texture* prevsprite = animator.entity.sprite;
unsigned int frame = 0;
float time_f = ((float)(animation.images.size()) / fps) / animation.images.size();
chrono::seconds time{static_cast<long int>(time_f)};    // time it should take to play the animation 
if (State == animation.stateActivate) {
vector<SDL_Texture*> real_images;
for(auto it = animation.images.begin(); it != animation.images.end(); ++it ){
	 real_images.push_back(createImageTexture(loadImage(*it),rend)); 
}
}
else {
animator.entity.sprite = prevsprite;
}
}
// Asynchronously play the animation
void playAnimation (animator_t animator,animation_t animation,unsigned int fps,SDL_Renderer *rend) {
     future<void> anim = async(launch::async,
		     	       playanimation_interrupting,
			       animator,animation,fps,rend);
     future_status status;
     while (true) {
	     this_thread::sleep_for(chrono::milliseconds(22));
	     status = anim.wait_for(chrono::milliseconds(1));
	     if(status == future_status::ready) {
		     break;
	     }
     }
}

