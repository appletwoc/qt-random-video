#include "video_button.hpp"
#include <iostream>

VideoButton::VideoButton(const char** videos, int n_videos){
	m_viewing_window = new QVideoWidget;
	m_viewing_window->setGeometry(100, 100, 300, 400);


	
	m_video_player = new SkipPlayer(videos, n_videos);

	m_video_player->setOutput(m_viewing_window);

	m_layout = new QVBoxLayout(m_viewing_window);
      m_layout->setContentsMargins(0, 0, 0, 0);

	m_randomize = new QPushButton;

	connect(m_randomize, &QPushButton::clicked, [&] (){
		std::cout << "Clicked\n";
		this->playMedia();
	});

	m_layout->addWidget(m_randomize);
}

void VideoButton::playMedia() const{
	this->m_viewing_window->show();
	this->m_video_player->getRandomVideo();
	this->m_video_player->playVideo();
}
