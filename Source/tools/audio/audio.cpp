#include"../../global.h"
//#include"../../../iirklang/include/irrKlang.h" // I dont have to do this but I like the autocorrect (will change to <irrKlang.h> when finished)
#include<irrKlang.h>
using namespace std;
using namespace irrklang;
int AUDIO_play (const char* file,bool looping) {
	ISoundEngine* engine = createIrrKlangDevice();
	if (!engine) {
	   printf("Audio -> FATAL : could not init audio engine");
	   return 1;
	}
	engine->play2D(file,looping);
	engine->drop();
	return 0;
}
