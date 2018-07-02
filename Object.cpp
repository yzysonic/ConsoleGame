#include "Object.h"

Object::Node::Node(void) : Node(nullptr){}
Object::List Object::list;

Object::Node::Node(Object * object)
{
	this->object = object;
	next = nullptr;
}

void Object::Node::Step(void)
{
	object = next->object;
	next = next->next;
}

Object::List::List(void)
{
	begin = end = new Node;
	last = nullptr;
	size = 0;
}

void Object::List::PushBack(Object * object)
{
	auto node = new Node(object);

	if (last)
	{
		last->next = node;
	}
	else
	{
		begin = last = node;
	}

	node->next = end;
	size++;
}

void Object::List::Erase(Object * object)
{
	if (begin->object == object)
	{
		begin = begin->next;
		delete begin;
	}

	for (auto ptr = begin; ptr != end; ptr->Step())
	{
		if (ptr->next->object == object)
		{
			auto target = ptr->next;
			ptr->next = ptr->next->next;
			delete target;
		}
	}
	size--;
}

size_t Object::List::Size(void)
{
	return size;
}

Object * Object::List::At(size_t index)
{
	if (index >= size || index < 0)
	{
		return nullptr;
	}

	auto ptr = begin;

	for (size_t i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}

	return ptr->object;
}

Object::Node Object::List::Begin(void)
{
	return *begin;
}

Object::Node Object::List::End(void)
{
	return *end;
}

void Object::UpdateAll(void)
{
	for (auto node = list.Begin(); node.next != nullptr; node.Step())
	{
		node.object->Update();
	}
}

void Object::PrintList(void)
{
	for (auto node = list.Begin(); node.next != nullptr; node.Step())
	{
		printf("%x -> ", (unsigned int)node.object);
	}
	printf("\n");
}

Object::Object(void)
{
	list.PushBack(this);
}

Object::~Object(void)
{
	list.Erase(this);
}
