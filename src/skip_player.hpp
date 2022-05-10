#ifndef SKIP_PLAYER_HPP
#define SKIP_PLAYER_HPP

#include <QWidget>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <random>

class SkipPlayer: public QWidget{
public:
	SkipPlayer(const char** videos, int n_videos, QVideoWidget* video_window);

	void getRandomVideo();
	void playVideo() const;

private:
	QMediaPlayer* m_player;
	const char** m_video_array;
	int m_n_videos;
	int m_current_video;
	int m_last_played; // Last played video to make sure the same video is not played twice in a row
};

#endif // SKIP_PLAYER_HPP
