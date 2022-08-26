#include<audio_out.h>
#include"../../global.h"
#include<vector>
#include<algorithm>
using namespace std;
using namespace anshub;
AudioOut audio {} ;
vector<string> playing ;
int PlayAudio (string file,bool looping) {
	playing.push_back(file);
	audio.Play(file,looping);
	return 0;
}
int stopAudio (string file) {
	if (find(playing.begin(),playing.end(),file) != playing.end())
	{
		audio.Stop(file);
		playing.erase(find(playing.begin(),playing.end(),file));	
	}
	else
	{
		printf("couldn't find file to stop playing");
		return 1;
	}
	return 0;
}
int AUDIO_DISPOSE () {
	audio_helpers::StopAllNowPlaying(audio, true);
	return 0;
}
