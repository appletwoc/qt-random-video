#include <QApplication>
#include "video_player.hpp"

int main(int argc, char **argv){
	QApplication app (argc, argv);

	int n_videos = 5;
	const char* vids[n_videos] = {"/home/dcruz/Videos/random/bf1_1.mp4",
		"/home/dcruz/Videos/random/bf1_2.mp4",
		"/home/dcruz/Videos/random/bf1_3.mp4",
		"/home/dcruz/Videos/random/bf1_4.mp4",
		"/home/dcruz/Videos/random/bf1_5.mp4"};

	//////////////////////////////////
	// SHORT VIDEO FOR DEBUG PURPOSES
	//////////////////////////////////
	
	// int n_videos = 1;
	// const char* vids[n_videos] = {"/home/dcruz/Videos/random/bf1_short.mp4"};

	VideoPlayer player(vids, n_videos);
	player.playMedia();

	return app.exec();
}
