#include"../../global.h"
//#include"../../../irrklang/include/irrKlang.h" // I dont have to do this but I like the autocorrect (will change to <irrKlang.h> when finished)
//multithreading
#include<thread>
#include<future>
#include<chrono>
#include<irrKlang.h>
#include<unistd.h>
using namespace std;
using namespace irrklang;
ISoundEngine* engine = createIrrKlangDevice();
void AUDIO_play (const char* file,bool looping) {
	usleep(68000);
	if (!engine) {
	   printf("Audio -> FATAL : could not init audio engine");
	   EXIT_FAILURE;
	}
	engine->play2D(file,looping);
}
void play_Audio (const char* file,bool looping) {
	future<void> audio = async(launch::async,
			           AUDIO_play,
				   file,looping);
	future_status status;
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(22));
		status = audio.wait_for(chrono::milliseconds(1));
		if(status == future_status::ready) {
			break;
		}
	}
}
void drop_engine () {
	engine->drop();
}
