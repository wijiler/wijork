#include"../../global.h"
#include"unistd.h"
#include<thread>
#include<future>
#include<chrono>

using namespace std;
string state;
class animation {
	public:
		string activation_state;
		vector<SDL_Surface*> frames;		
		int frame;
	 void animate ();	
	 bool checkState () {
		while (true) {
		usleep(12000);
		if (state == this->activation_state)
		{
			return true;
			break;
		}
		else {
			return false;
			continue;
		}
		}
		return false;
	}
};
// animate
void animation::animate () {	
	     future<bool> animState = async(launch::async,
			     		    &animation::checkState,
					    this);
}
