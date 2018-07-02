#pragma once
#include "Common.h"
#include "Singleton.h"

enum class KeyCode
{
	Backspace = 0
};

class Input : public Singleton<Input>
{
	friend class Singleton<Input>;

public:
	static constexpr int NumKeyMax = 256;

public:
	void Update(void);
	bool GetKey(BYTE key);
	bool GetKeyDown(BYTE key);
	bool GetKeyUp(BYTE key);

private:
	BYTE last_key_state[NumKeyMax];
	BYTE key_state_down[NumKeyMax];
	BYTE key_state_up[NumKeyMax];

	Input(void);
};