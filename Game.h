#pragma once
#include "Common.h"
#include "Console.h"
#include "Input.h"
#include "Renderer.h"
#include "Time.h"

class Game
{
public:
	static void Init(void);
	static void Run(void);
	static void Stop(void);
	static void Uninit(void);

private:
	static bool run;
	static Console	* console;
	static Input	* input;
	static Renderer * renderer;
	static Time		* time;
};

