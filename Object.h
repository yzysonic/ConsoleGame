#pragma once
#include "Common.h"

class Object
{
	//=========  内部クラス宣言  =========//
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

	//=========  Staticメンバー宣言  =========//
public:
	static void UpdateAll(void);
	static void PrintList(void);

private:
	static List list;

	//===========  メンバー宣言  ===========//
public:

	Object(void);
	~Object(void);
	virtual void Update(void) {};

};
