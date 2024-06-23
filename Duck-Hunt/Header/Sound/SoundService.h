#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		GAME_OVER,
		WAVE_CLEAR,
		WAVE_NOT_CLEAR
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;

		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_bullet_fire;
		sf::SoundBuffer buffer_game_over;
		sf::SoundBuffer buffer_wave_clear;
		sf::SoundBuffer buffer_wave_not_clear;

		sf::String background_music_path = "assets/Sounds/MainTheme.mp3";
		sf::String button_click_sound_path = "assets/Sounds/click.wav";
		sf::String bullet_fire_sound_path = "assets/Sounds/fire.mp3";
		sf::String game_over_sound_path = "assets/Sounds/gameOver.mp3";
		sf::String wave_clear_sound_path = "assets/Sounds/waveClear.mp3";
		sf::String wave_not_clear_sound_path = "assets/Sounds/waveNotClear.mp3";


		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void initialize();

		void playSound(SoundType soundType);
		void playBackgroundMusic();
	};
}