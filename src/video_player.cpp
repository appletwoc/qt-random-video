#include "video_player.hpp"
#include <iostream>

VideoPlayer::VideoPlayer(){
	m_viewing_window = new QVideoWidget;
	m_viewing_window->setGeometry(1280, 720, 1280, 720);

	m_player = new QMediaPlayer;

	m_player->setVideoOutput(m_viewing_window);

	// Have not played a video when constructed
	m_last_played = -1;

	// Not currently playing video
	m_current_video = -1;

	// Create the button
	const QSize btnSize = QSize(200, 40);
	m_randomize_button = new QPushButton("Play");
	m_randomize_button->setFixedSize(btnSize);
	m_randomize_button->setEnabled(false);

	m_open = new QPushButton("Open...");
	m_open->setFixedSize(btnSize);

	// Connect the button to a function
	connect(m_randomize_button, &QPushButton::clicked, this, &VideoPlayer::playMedia);
	connect(m_open, &QPushButton::clicked, this, &VideoPlayer::openFile);

	// Connect m_player
	connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &VideoPlayer::mediaStatusChanged);
	
	// Creating the layout
	// For the randomize button
	QBoxLayout* buttons = new QHBoxLayout;
	buttons->setContentsMargins(0, 0, 0, 0);
	buttons->addWidget(m_randomize_button);
	buttons->addWidget(m_open);
	

	QBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addWidget(m_viewing_window);
	main_layout->addLayout(buttons);

	if(layout() == nullptr){
		this->setLayout(main_layout);
	}

	this->show();
}

void VideoPlayer::openFile(){
	m_video_array = QFileDialog::getOpenFileNames(this, "Open video..", QDir::homePath(),
														 "Videos (*.mp4)");

	if(m_video_array.size() != 0){
		m_randomize_button->setEnabled(true);
	}
}


void VideoPlayer::getRandomVideo(){
	std::random_device rand;
	std::mt19937 rng(rand());

	
	do{
		std::uniform_int_distribution<std::mt19937::result_type>dist6(0, m_video_array.size() - 1);
		m_current_video = dist6(rng);
	} while(m_current_video == m_last_played && m_video_array.size() > 1);
	
	    m_last_played = m_current_video;

		this->m_player->setMedia(QUrl::fromLocalFile(this->m_video_array.at(m_current_video)));
}

void VideoPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus state){
	// std::cout << "changed to state: " << state << '\n';
	if(state == QMediaPlayer::EndOfMedia){
		// std::cout << "Ended media\n";
		// this->m_player->setPosition(0);
		this->m_player->setMedia(QUrl::fromLocalFile(this->m_video_array.at(m_current_video)));
		this->m_player->play();
	}
}


void VideoPlayer::playMedia(){
	this->m_viewing_window->show();
	m_randomize_button->setText("Randomize");
	
	if(m_video_array.size() != 0){
		this->getRandomVideo();
		this->m_player->play();
	}
}
