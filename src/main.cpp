#include <QApplication>
#include "video_player.hpp"

int main(int argc, char **argv){
	QApplication app (argc, argv);
	////////////////////////////////
	// MODIFY THIS:
	////////////////////////////////
	
	// Number of videos //
	int n_videos = 5;

	// Video paths //
	const char* vids[n_videos] = {
		// Replace with the paths of the videos stored on the drive
		"/home/dcruz/Videos/random/bf1_1.mp4",
		"/home/dcruz/Videos/random/bf1_2.mp4",
		"/home/dcruz/Videos/random/bf1_3.mp4",
		"/home/dcruz/Videos/random/bf1_4.mp4",
		"/home/dcruz/Videos/random/bf1_5.mp4",
	};

	////////////////////////////////
	// END OF MODIFY AREA
	////////////////////////////////

	//////////////////////////////////
	// SHORT VIDEO FOR DEBUG PURPOSES
	//////////////////////////////////
	
	// int n_videos = 1;
	// const char* vids[n_videos] = {"/home/dcruz/Videos/random/bf1_short.mp4"};

	VideoPlayer player(vids, n_videos);
	player.playMedia();

	return app.exec();
}
