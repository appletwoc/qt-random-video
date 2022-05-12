#ifndef VIDEO_BUTTON_H
#define VIDEO_BUTTON_H

#include "skip_player.hpp"
#include <QWidget>
#include <QPushButton>
#include <QVideoWidget>
#include <QVBoxLayout>

class VideoButton: public QWidget{
public:
	VideoButton(const char** videos, int n_videos);

	void playMedia() const;

private:
	QPushButton* m_randomize;
	QVBoxLayout* m_layout;
	QVideoWidget* m_viewing_window;
	SkipPlayer* m_video_player;
};

#endif // VIDEO_BUTTON_H
