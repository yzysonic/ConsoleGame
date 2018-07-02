#include "Renderer.h"
#include <stdlib.h>

void Renderer::BeginScene(void)
{
	ReadConsoleOutput(console->GetOutputHandle(), (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

void Renderer::EndScene(void)
{
}

void Renderer::SetTransform(void)
{
}

void Renderer::Draw(void)
{
	for (int y = 0; y < SCREEN_HEIGHT; ++y)
	{
		for (int x = 0; x < SCREEN_WIDTH; ++x)
		{
			buffer[x + SCREEN_WIDTH * y].Char.AsciiChar = (unsigned char)0;
			buffer[x + SCREEN_WIDTH * y].Attributes = 200;
			//buffer[x + SCREEN_WIDTH * y].Attributes = rand() % 256;
		}
	}
	//buffer[5][10].Char.AsciiChar = (unsigned char)219;
	//buffer[5][10].Attributes = 0x0E;
	//buffer[5][11].Char.AsciiChar = '¡';
	//buffer[5][11].Attributes = 0x0B;
	//buffer[5][12].Char.AsciiChar = '¡';
	//buffer[5][12].Attributes = 0x0A;
}

void Renderer::Present(void)
{
	WriteConsoleOutput(console->GetOutputHandle(), (CHAR_INFO *)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

void Renderer::Render(void)
{
	BeginScene();
	Draw();
	EndScene();
	Present();
}

Renderer::Renderer(void)
{
	console = Console::GetInstance();

	dwBufferSize.X		= SCREEN_WIDTH;
	dwBufferSize.Y		= SCREEN_HEIGHT;

	dwBufferCoord.X		= 0;
	dwBufferCoord.Y		= 0;
	
	rcRegion.Left		= 0;
	rcRegion.Top		= 0;
	rcRegion.Right		= SCREEN_WIDTH - 1;
	rcRegion.Bottom		= SCREEN_HEIGHT - 1;
}
