#include "../../header/Sound/SoundService.h"

namespace Sound
{

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(background_music_path))
			printf("Error loading background music file");
		playBackgroundMusic();
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(button_click_sound_path))
			printf("Error loading click music file");
		if (!buffer_bullet_fire.loadFromFile(bullet_fire_sound_path))
			printf("Error loading fire music file");
		if (!buffer_game_over.loadFromFile(game_over_sound_path))
			printf("Error loading game over music file");
		if (!buffer_wave_clear.loadFromFile(wave_clear_sound_path))
			printf("Error loading wave music file");
		if (!buffer_wave_not_clear.loadFromFile(wave_not_clear_sound_path))
			printf("Error loading wave music file");
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			sound_effect.play();
			break;

		case SoundType::BULLET_FIRE:
			sound_effect.setBuffer(buffer_bullet_fire);
			sound_effect.play();
			break;
		case SoundType::GAME_OVER:
			sound_effect.setBuffer(buffer_game_over);
			sound_effect.play();
			break;
		case SoundType::WAVE_CLEAR:
			sound_effect.setBuffer(buffer_wave_clear);
			sound_effect.play();
			break;
		case SoundType::WAVE_NOT_CLEAR:
			sound_effect.setBuffer(buffer_wave_not_clear);
			sound_effect.play();
		default:
			printf("Invalid sound type");
			return;
		}
	}

	void SoundService::playBackgroundMusic()
	{
		printf("mu play");
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
}