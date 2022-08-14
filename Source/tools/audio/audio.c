#define MINIAUDIO_IMPLEMENTATION
#include"miniaudio.h"
int playsound (char* filename) {
	ma_engine engine;
	ma_result result;
	ma_sound sound;
	result = ma_sound_init_from_file(&engine,filename,0,NULL,NULL,&sound);
	if(result != MA_SUCCESS){
		printf("failed to play sound");
		return -1;
	}
	ma_sound_start(&sound);
	return 0;
}
