#include "Game.h"
#include "Scene.h"
#include "Object.h"
#include "Collider.h"

bool		Game::run = false;
Console		* Game::console;
Input		* Game::input;
Renderer	* Game::renderer;
Time		* Game::time;

void Game::Init(void)
{
	console		= Console::GetInstance();
	input		= Input::GetInstance();
	renderer	= Renderer::GetInstance();
	time		= Time::GetInstance();
}

void Game::Run(void)
{
	run = true;

	while (run)
	{
		console->Update();
		input->Update();
		Scene::UpdateCurrnetScene();
		Object::UpdateAll();
		Collider::TestCollition();
		renderer->Render();
		time->FramerateControl();
	}
}

void Game::Stop(void)
{
	run = false;
}

void Game::Uninit(void)
{
	Renderer::Destroy();
	Input::Destroy();
	Console::Destroy();
}
