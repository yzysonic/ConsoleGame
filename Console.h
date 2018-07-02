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
	HANDLE output_handle;			// �W���o�̓n���h��
	HANDLE input_handle;			// �W�����̓n���h��
	DWORD event_count;				// �C�x���g�̐�
	DWORD event_read_count;			// �ǂݍ��񂾃C�x���g�̐�
	INPUT_RECORD event_buffer[128];	// �C�x���g�̃o�b�t�@�[
	BYTE key_state[NumKeyMax];

	Console(void);

};