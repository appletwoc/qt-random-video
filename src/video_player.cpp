#include "video_player.hpp"
#include <iostream>

VideoPlayer::VideoPlayer(const char** videos, int n_videos){
	m_viewing_window = new QVideoWidget;
	m_viewing_window->setGeometry(1280, 720, 1280, 720);

	m_player = new QMediaPlayer;
	m_n_videos = n_videos;

	m_player->setVideoOutput(m_viewing_window);
	m_video_array = videos;

	// Have not played a video when constructed
	m_last_played = -1;

	// Not currently playing video
	m_current_video = -1;

	// Create the button
	const QSize btnSize = QSize(200, 40);
	m_randomize_button = new QPushButton("Randomize");

	m_randomize_button->setFixedSize(btnSize);

	// Connect the button to a function
	connect(m_randomize_button, &QPushButton::clicked, this, &VideoPlayer::playMedia);

	// Connect m_player
	connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &VideoPlayer::mediaStatusChanged);
	
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

void VideoPlayer::getRandomVideo(){
	std::random_device rand;
	std::mt19937 rng(rand());

	do{
		std::uniform_int_distribution<std::mt19937::result_type>dist6(0, this->m_n_videos - 1);
		m_current_video = dist6(rng);
	} while(m_current_video == m_last_played);
	
	    m_last_played = m_current_video;

	this->m_player->setMedia(QUrl::fromLocalFile(this->m_video_array[m_current_video]));
}

void VideoPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus state){
	// std::cout << "changed to state: " << state << '\n';
	if(state == QMediaPlayer::EndOfMedia){
		// std::cout << "Ended media\n";
		// this->m_player->setPosition(0);
		this->m_player->setMedia(QUrl::fromLocalFile(this->m_video_array[m_current_video]));
		this->m_player->play();
	}
}


void VideoPlayer::playMedia(){
	this->m_viewing_window->show();
	this->getRandomVideo();
	this->m_player->play();
}
