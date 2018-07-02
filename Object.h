#pragma once
#include "Common.h"

class Object
{
	//=========  �����N���X�錾  =========//
public:
	class Node
	{
	public:
		Object	* object;
		Node	* next;

		Node(void);
		Node(Object * object);
		void Step(void);
	};

	class List
	{
	public:
		List(void);
		void PushBack(Object * object);
		void Erase(Object * object);
		size_t Size(void);
		Object * At(size_t index);
		Node Begin(void);
		Node End(void);

	private:
		Node * begin;
		Node * last;
		Node * end;
		size_t size;
	};

	//=========  Static�����o�[�錾  =========//
public:
	static void UpdateAll(void);
	static void PrintList(void);

private:
	static List list;

	//===========  �����o�[�錾  ===========//
public:

	Object(void);
	~Object(void);
	virtual void Update(void) {};

};
