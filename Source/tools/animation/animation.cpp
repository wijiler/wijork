#include"../../global.h"	
#include"../entity.h"
#include<chrono>
#include<thread>
#include<future>
using namespace std;
// TODO: make the animation accept mp4 format as well
typedef struct {
	vector<SDL_Texture*> images;	
	//SDL_Texture* image;
	string stateActivate;

}animation_t;
typedef struct {
	string State;
	vector<string> States;
	entity2D entity;
}animator_t;
// NOTE: do not use this function under any circumstances as it will pause the game,also this code fucking sucks
void playanimation_interrupting (animator_t animator,animation_t animation,unsigned int fps) {
SDL_Texture* prevsprite = animator.entity.sprite;
unsigned int frame = 0;
float time_f = ((float)(animation.images.size()) / fps) / animation.images.size();
chrono::seconds time{static_cast<long int>(time_f)};    // time it should take to play the animation 
while(animator.State == animation.stateActivate) // wait till the state is right to play the animation
{
for(auto & it : animation.images) {	
	 animator.entity.sprite = it;	
	 frame++;
	 this_thread::sleep_for(time);
	 if (frame >= animation.images.size()) {
	     frame = 0;
	     animator.entity.sprite = animation.images.front();
	     continue;
	 }	
	 
 }
} 
animator.entity.sprite = prevsprite;
}
// Asynchronously play the animation
void playAnimation (animator_t animator,animation_t animation,unsigned int fps) {
     future<void> anim = async(launch::async,
		     	       playanimation_interrupting,
			       animator,animation,fps);
     future_status status;
     while (true) {
	     this_thread::sleep_for(chrono::milliseconds(22));
	     status = anim.wait_for(chrono::milliseconds(1));
	     if(status == future_status::ready) {
		     break;
	     }
     }
}

