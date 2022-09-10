#include"../../global.h"	
#include"../entity.h"
#include<bits/stdc++.h>
using namespace std;
// TODO: make the animation accept mp4 format as well
typedef struct {
	unsigned int frame;
	vector<SDL_Texture*> images;	
	string stateActivate;

}animation_t;
typedef struct {
	string State;
	vector<string> States;
	entity2D entity;
}animator_t;
// NOTE: do not use this function under any circumstances as it will pause the game!
void playanimation_interrupting (animator_t animator,animation_t animation) {
while(animator.State == animation.stateActivate) // wait till the state is right to play the animation
{
for(auto & it : animation.images) {

}
} 

}
// Asynchronously play the animation
void playAnimation () {
}
