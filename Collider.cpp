#include "Collider.h"

List<Collider*> Collider::list;

void Collider::TestCollition(void)
{
	for (auto collider : list)
	{

	}
}

Collider::Collider(Object * object) : object(object)
{
	list.push_back(this);
}

Collider::~Collider(void)
{
	list.erase(this);
}
