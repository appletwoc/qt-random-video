#include "video_player.hpp"
#include <iostream>

VideoPlayer::VideoPlayer(const char** videos, int n_videos){
	m_viewing_window = new QVideoWidget;
	m_viewing_window->setGeometry(100, 100, 300, 400);

	m_video_player = new SkipPlayer(videos, n_videos);
	m_video_player->setOutput(m_viewing_window);


	m_randomize_button = new QPushButton("Randomize");

	connect(m_randomize_button, &QPushButton::clicked, this, &VideoPlayer::playMedia);
	
	// Creating the layout
	
	// For the randomize button
	QBoxLayout* rand_button = new QHBoxLayout;
	rand_button->setContentsMargins(0, 0, 0, 0);
	rand_button->addWidget(m_randomize_button);

	QBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addWidget(m_viewing_window);
	main_layout->addLayout(rand_button);

	if(layout() == nullptr){
		this->setLayout(main_layout);
	}

	this->show();
}

void VideoPlayer::playMedia() const{
	this->m_viewing_window->show();
	this->m_video_player->getRandomVideo();
	this->m_video_player->playVideo();
}
