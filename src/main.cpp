#include <QApplication>
#include "video_player.hpp"

int main(int argc, char **argv){
	QApplication app (argc, argv);
	app.setApplicationName("Reelz Simulator");

	VideoPlayer player;
	player.setWindowTitle("Reelz Simulator");
	player.setGeometry(100, 100, 500, 915);

	return app.exec();
}
