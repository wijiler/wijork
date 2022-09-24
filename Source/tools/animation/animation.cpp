#include"../../global.h"	
#include"../entity.h"
#include<bits/stdc++.h>
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
// NOTE: do not use this function under any circumstances as it will pause the game!
void playanimation_interrupting (animator_t animator,animation_t animation) {
unsigned int frames = animation.images.size();
unsigned int frame = 0;
while(animator.State == animation.stateActivate) // wait till the state is right to play the animation
{
for(auto & it : animation.images) {
	 animator.entity.sprite = it;	
	 frame++;
	 if (frame >= frames) {
	     frame = 0;
	     animator.entity.sprite = animation.images.front();
	     continue;
	 }
 }
} 

}
// Asynchronously play the animation
void playAnimation () {
}
