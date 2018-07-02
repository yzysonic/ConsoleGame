#include "SceneGame.h"

void SceneGame::Update(void)
{
	if (Input::GetInstance()->GetKeyUp(VK_ESCAPE))
	{
		Game::Stop();
	}
}
