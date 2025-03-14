#include "audiomanager.h"

AudioManager::AudioManager()
{
	position = 0;
}

AudioManager::~AudioManager()
{
	bgm->release(); //Release BGM
	titleMusic->release(); //Release titlemusic

	while (!vecSounds.empty()) //Release sounds in sound vector
	{
		FMOD::Sound* tempSound = vecSounds.back();
		vecSounds.pop_back();
		tempSound->release();
	}

	audioSystem->release();
}

void AudioManager::Initialise()
{
	FMOD_RESULT result;
	result = FMOD::System_Create(&audioSystem);
	result = audioSystem->init(100, FMOD_INIT_NORMAL | FMOD_INIT_3D_RIGHTHANDED, 0);
	result = audioSystem->getChannel(0, &channelA);

	//BGM
	result = audioSystem->createSound("Assets/METALDEATH.wav", FMOD_DEFAULT | FMOD_CREATESAMPLE | FMOD_LOOP_NORMAL, 0, &bgm);
	result = audioSystem->playSound(bgm, 0, false, &channelA);
}

void AudioManager::Update()
{
	audioSystem->update();
}

unsigned int AudioManager::GetBGMPosition() const
{
	return position;
}

unsigned int AudioManager::GetBGMLength() const
{
	return length;
}

float AudioManager::GetVolume() const
{
	return volume;
}

FMOD::System * AudioManager::GetAudioSystem()
{
	return audioSystem;
}

void AudioManager::AddSoundToVector(FMOD::Sound * _sound)
{
	vecSounds.push_back(_sound);
}

void AudioManager::PlayBGM(bool _play)
{
	if (_play) //Play Channel A
	{
		channelB->setPaused(true);
		channelB->setPosition(0, FMOD_TIMEUNIT_MS);
		channelA->setPaused(false);
	}
	else //Play Channel B
	{
		channelA->setPaused(true);
		channelA->setPosition(0, FMOD_TIMEUNIT_MS);
		channelB->setPaused(false);
	}
}

void AudioManager::ReleaseSFX()
{
	while (!vecSounds.empty()) //Release sounds in sound vector
	{
		FMOD::Sound* tempSound = vecSounds.back();
		vecSounds.pop_back();
		tempSound->release();
	}
}
