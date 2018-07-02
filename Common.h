#pragma once

#define GAME_TITLE		("Mini Game")
#define SCREEN_WIDTH	(80)
#define SCREEN_HEIGHT	(25)
#define FPS				(30)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

template<class T>
void SafeDelete(T *&ptr)
{
	delete ptr;
	ptr = nullptr;
}

template<class T>
void SafeRelease(T *&ptr)
{
	if (ptr == nullptr) return;
	ptr->Release();
	ptr = nullptr;
}

