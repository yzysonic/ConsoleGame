#pragma once
#include "Common.h"
#include "List.h"
#include "Vector.h"
#include "Object.h"

class Object;

class Collider
{
public:
	static List<Collider*> list;
	static void TestCollition(void);


public:
	Object * const object;

	Collider(Object * object);
	~Collider(void);
};