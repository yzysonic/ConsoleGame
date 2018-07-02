#include "Input.h"
#include "Console.h"

void Input::Update(void)
{
	auto key_state = Console::GetInstance()->GetKeyState();

	for (int i = 0; i < NumKeyMax; i++)
	{
		key_state_down[i]	= (last_key_state[i] ^ key_state[i]) & key_state[i];
		key_state_up[i]		= (last_key_state[i] ^ key_state[i]) & ~key_state[i];
	}
	
	memcpy(last_key_state, key_state, NumKeyMax);
}

bool Input::GetKey(BYTE key)
{
	return last_key_state[key];
}

bool Input::GetKeyDown(BYTE key)
{
	return key_state_down[key];
}

bool Input::GetKeyUp(BYTE key)
{
	return key_state_up[key];
}

Input::Input(void)
{
	ZeroMemory(last_key_state, NumKeyMax);
}
