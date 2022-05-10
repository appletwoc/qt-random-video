#include "skip_player.hpp"
#include <iostream>

SkipPlayer::SkipPlayer(const char** videos, int n_videos, QVideoWidget* video_window){
	// Set the media player to the play videos
	m_player = new QMediaPlayer;
	m_player->setVideoOutput(video_window);

	m_n_videos = n_videos;
	m_last_played = -1;
	
	// Allocate the paths for the videos
	m_video_array = videos;
}

void SkipPlayer::getRandomVideo(){
	std::random_device rand;
	std::mt19937 rng(rand());
	std::uniform_int_distribution<std::mt19937::result_type>dist6(0, this->m_n_videos - 1);

	// if(this->m_last_played != -1){
	// 	this->m_last_played = this->m_current_video;
	// }

	this->m_player->setMedia(QUrl::fromLocalFile(this->m_video_array[dist6(rng)]));
}

void SkipPlayer::playVideo() const{
	
	this->m_player->play();
}
