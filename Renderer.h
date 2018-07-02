#pragma once
#include "Common.h"
#include "Console.h"
#include "Singleton.h"

class Renderer : public Singleton<Renderer>
{
	friend class Singleton<Renderer>;

public:
	void SetBuffer(void);
	void SetTransform(void);
	void Draw(void);
	void Render(void);

private:
	Console * console;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
	CHAR_INFO buffer[SCREEN_HEIGHT*SCREEN_WIDTH];

	Renderer(void);
	void BeginScene(void);
	void EndScene(void);
	void Present(void);

};