#include "Scene.h"

Scene * Scene::current_scene = nullptr;

void Scene::SetScene(Scene * scene)
{
	if (current_scene)
	{
		current_scene->Uninit();
		delete current_scene;
	}

	current_scene = scene;

	if (scene)
	{
		scene->Init();
	}
}

Scene * Scene::GetCurrentScene(void)
{
	return current_scene;
}

void Scene::UpdateCurrnetScene(void)
{
	current_scene->Update();
}
