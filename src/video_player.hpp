#ifndef VIDEO_BUTTON_H
#define VIDEO_BUTTON_H

#include <QWidget>
#include <QtMultimedia>
#include <QPushButton>
#include <QVideoWidget>
#include <QBoxLayout>
#include <random>

class VideoPlayer: public QWidget{
public:
	VideoPlayer(const char** videos, int n_videos);

	void getRandomVideo();
	void playMedia();

private slots:
	void mediaStatusChanged(QMediaPlayer::MediaStatus state);

private:
	QPushButton* m_randomize_button;
	QVideoWidget* m_viewing_window;
	QMediaPlayer* m_player;
	const char** m_video_array;
	int m_n_videos;
	int m_last_played;
	int m_current_video;
};

#endif // VIDEO_BUTTON_H
