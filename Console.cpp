#include "Console.h"

void Console::Init(void)
{
	// カーソルを隠す
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(output_handle, &info);

	// ウィンドウサイズを設定
	SMALL_RECT windowSize = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SetConsoleWindowInfo(output_handle, TRUE, &windowSize);
}

void Console::Update(void)
{
	// キーステートをクリア
	ZeroMemory(key_state, NumKeyMax);

	GetNumberOfConsoleInputEvents(input_handle, &event_count);

	if (event_count <= 0)
		return;
	
	ReadConsoleInput(input_handle, event_buffer, event_count, &event_read_count);

	
	// イベント処理
	for (DWORD i = 0; i < event_read_count; i++)
	{
		switch (event_buffer[i].EventType)
		{
		case KEY_EVENT:
			if(event_buffer[i].Event.KeyEvent.bKeyDown)
				key_state[event_buffer[i].Event.KeyEvent.wVirtualKeyCode] = true;
			break;
		}
	}
	
	
}

HANDLE Console::GetOutputHandle(void)
{
	return output_handle;
}

HANDLE Console::GetInputHandle(void)
{
	return input_handle;
}

BYTE * Console::GetKeyState(void)
{
	return key_state;
}

Console::Console(void)
{
	input_handle	= (HANDLE)GetStdHandle(STD_INPUT_HANDLE);
	output_handle	= (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	Init();
}
