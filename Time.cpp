#include "Time.h"
#include <mmsystem.h>
#include <math.h>

#pragma comment (lib, "winmm.lib")

float Time::DeltaTime()
{
	return instance->delta_time;
}

Timer::Timer(float interval)
{
	this->start_time = timeGetTime();
	this->interval = (DWORD)(interval * 1000);
}

void Timer::Reset()
{
	this->start_time = timeGetTime();
}

float Timer::ElapsedTime()
{
	return (timeGetTime() - this->start_time) / 1000.0f;
}

bool Timer::TimeUp()
{
	if ((timeGetTime() - this->start_time) >= this->interval)
		return true;
	else
		return false;
}


void Time::FramerateControl()
{
	static DWORD elapsed, sleep, _elapsed, _error;

	// fpsŒv‘ª
	frame_count++;
	elapsed = timeGetTime() - fps_timer->start_time;
	if (frame_count == 30)
	{
		fps = (int)(frame_count / fps_timer->ElapsedTime());
		frame_count = 0;
		fps_timer->Reset();

#ifdef _DEBUG
		char s[256];
		sprintf_s(s, "%s FPS:%d", GAME_TITLE, fps);
		SetConsoleTitle(s);
#endif

	}

	// fps‡‚í‚¹
	elapsed = timeGetTime() - frame_timer->start_time;
	sleep = frame_timer->interval - min(elapsed, frame_timer->interval);
	if (sleep > 0)
	{
		Sleep(sleep);
		elapsed = (timeGetTime() - frame_timer->start_time);
	}
	
	delta_time = fminf(elapsed / 1000.0f, (1.0f / FPS) * 3);

	frame_timer->Reset();
}

Time::Time(void)
{
	timeBeginPeriod(1); // •ª‰ð”\‚ðÝ’è
	frame_timer = new Timer(1.0f / FPS);
	fps_timer = new Timer(1.0f);
	frame_error = 0;
	frame_count = 0;
}

Time::~Time(void)
{
	SafeDelete(frame_timer);
	SafeDelete(fps_timer);
}

FrameTimer::FrameTimer(float interval)
{
	this->elapsed = 0.0f;
	this->interval = interval;
}

void FrameTimer::Step(void)
{
	this->elapsed += Time::DeltaTime();
}

void FrameTimer::Reset(void)
{
	this->elapsed = 0.0f;
}

void FrameTimer::Reset(float interval)
{
	this->interval = interval;
	Reset();
}

float FrameTimer::Progress(void)
{
	return this->elapsed / this->interval;
}

float FrameTimer::Elapsed(void)
{
	return this->elapsed;
}

bool FrameTimer::TimeUp(void)
{
	if (this->interval < 0.0f)
		return false;
	else
		return this->elapsed >= this->interval;
}

void FrameTimer::operator++(int)
{
	Step();
}
