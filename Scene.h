#pragma once
#include "Common.h"

class Scene
{
public:
	static Scene * current_scene;
	static void SetScene(Scene * scene);
	static Scene * GetCurrentScene(void);
	static void UpdateCurrnetScene(void);

protected:
	virtual void Init(void) {};
	virtual void Update(void) {};
	virtual void Uninit(void) {};
};
