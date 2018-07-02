#pragma once
#include "Common.h"
#include "Singleton.h"

class Console : public Singleton<Console>
{
	friend class Singleton<Console>;

public:
	static constexpr int NumKeyMax = 256;

public:
	void Init(void);
	void Update(void);
	HANDLE GetOutputHandle(void);
	HANDLE GetInputHandle(void);
	BYTE* GetKeyState(void);

private:
	HANDLE output_handle;			// 標準出力ハンドル
	HANDLE input_handle;			// 標準入力ハンドル
	DWORD event_count;				// イベントの数
	DWORD event_read_count;			// 読み込んだイベントの数
	INPUT_RECORD event_buffer[128];	// イベントのバッファー
	BYTE key_state[NumKeyMax];

	Console(void);

};