#pragma once
#include "Common.h"
#include "Singleton.h"

class Timer
{
public:
	DWORD start_time;
	DWORD interval;

	Timer(float interval = 0.0f);
	void Reset(void);
	float ElapsedTime(void);
	bool TimeUp(void);
};

class FrameTimer
{
public:
	float interval;

	FrameTimer(float interval = 0.0f);
	void Step(void);
	void Reset(void);
	void Reset(float interval);
	float Progress(void);
	float Elapsed(void);
	bool TimeUp(void);
	void operator ++(int);

private:
	float elapsed;
};

class Time : public Singleton<Time>
{
	friend class Singleton<Time>;

public:
	static float DeltaTime(void);
	void FramerateControl();

private:
	Timer* frame_timer;
	Timer* fps_timer;
	DWORD frame_error;
	DWORD frame_count;
	float delta_time;
	size_t fps;

	Time(void);
	~Time(void);
};