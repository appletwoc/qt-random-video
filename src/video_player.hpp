#ifndef VIDEO_BUTTON_H
#define VIDEO_BUTTON_H

#include <QWidget>
#include <QtMultimedia>
#include <QPushButton>
#include <QVideoWidget>
#include <QFileDialog>
#include <QBoxLayout>
#include <QDir>
#include <chrono>
#include <random>

class VideoPlayer: public QWidget{
public:
	VideoPlayer();

	void getRandomVideo();
	void playMedia();


private slots:
	void mediaStatusChanged(QMediaPlayer::MediaStatus state);
	void openFile();
	void aboutMenu();
	void helpMenu();

private:
	QPushButton* m_randomize_button;
	QPushButton* m_open;
	QPushButton* m_about;
	QPushButton* m_help;
	QVideoWidget* m_viewing_window;
	QMediaPlayer* m_player;
	QStringList m_video_array;
	int m_last_played;
	int m_current_video;
};

#endif // VIDEO_BUTTON_H
