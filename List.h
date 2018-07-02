#pragma once
#include "Common.h"

template<class T>
class List;

// 汎用ノードクラス
template<class T>
class Node
{
	friend class List<T>;

public:
	Node(void) : Node<T>(nullptr) {}
	Node(T type)
	{
		this->type = type;
		next = nullptr;
	}
	T operator *(void) const
	{
		return type;
	}
	T* operator ->(void) const
	{
		return &type;
	}
	void operator ++(void)
	{
		type = next->type;
		next = next->next;
	}
	bool operator ==(Node<T>& node) const
	{
		return (type == node.type) && (next == node.next);
	}
	bool operator !=(Node<T>& node) const
	{
		return (type != node.type) || (next != node.next);
	}

private:
	T type;
	Node<T> * next;
};

// 汎用リストクラス
template<class T>
class List
{
public:
	List(void)
	{
		m_Begin = m_end = new Node<T>;
		m_Last = nullptr;
		m_size = 0;
	}
	void push_back(T type)
	{
		auto node = new Node<T>(type);

		if (m_Last)
		{
			m_Last->next = node;
		}
		else
		{
			m_Begin = m_Last = node;
		}

		node->next = m_end;
		m_size++;
	}
	void erase(T type)
	{
		if (m_Begin->type == type)
		{
			m_Begin = m_Begin->next;
			delete m_Begin;
		}

		for (auto ptr = m_Begin; ptr != m_end; ptr++)
		{
			if (ptr->next->type == type)
			{
				auto target = ptr->next;
				ptr->next = ptr->next->next;
				delete target;
			}
		}
		m_size--;
	}
	size_t size(void) const
	{
		return m_size;
	}
	T at(int index) const
	{
		if (index >= m_size || index < 0)
		{
			return nullptr;
		}

		auto ptr = m_Begin;

		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}

		return ptr->object;
	}
	Node<T> begin(void) const
	{
		return *m_Begin;
	}
	Node<T> end(void) const
	{
		return *m_end;
	}

private:
	Node<T> * m_Begin;
	Node<T> * m_Last;
	Node<T> * m_end;
	size_t m_size;
};

