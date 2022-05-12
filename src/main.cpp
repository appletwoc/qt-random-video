#include <QApplication>
#include "skip_player.hpp"
#include "video_player.hpp"

int main(int argc, char **argv){
	QApplication app (argc, argv);

	int n_videos = 5;
	const char* vids[n_videos] = {"/home/dcruz/Videos/random/bf1_1.mp4",
		"/home/dcruz/Videos/random/bf1_2.mp4",
		"/home/dcruz/Videos/random/bf1_3.mp4",
		"/home/dcruz/Videos/random/bf1_4.mp4",
	"/home/dcruz/Videos/random/bf1_5.mp4"};

	// // Setting the viewing window (canvas)
	// QVideoWidget* vw = new QVideoWidget;
	// vw->setGeometry(100, 100, 300, 400);
	// vw->show();

	// // Creating the video player
	// SkipPlayer player(vids, n_videos, vw);

	// player.getRandomVideo();
	// player.playVideo();

	VideoPlayer player(vids, n_videos);
	player.playMedia();

	// Next: Have video loop until button pressed

	return app.exec();
}
