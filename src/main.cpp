#include <QApplication>
#include "video_player.hpp"

int main(int argc, char **argv){
	QApplication app (argc, argv);

	VideoPlayer player;
	player.setGeometry(100, 100, 720, 720);

	return app.exec();
}
