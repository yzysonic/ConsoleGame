#include "Game.h"
#include "Scene.h"
#include "SceneGame.h"

void main(void)
{
	Game::Init();

	Scene::SetScene(new SceneGame);

	Game::Run();
	Game::Uninit();
}