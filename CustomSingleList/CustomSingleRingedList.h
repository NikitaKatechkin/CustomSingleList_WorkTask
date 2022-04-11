#pragma once

#include "CustomSingleListNode.h"

template <typename T>
class CustomSingleRingedList
{
public:
	CustomSingleRingedList() = default;
	~CustomSingleRingedList() = default;

	/**
	CustomSingleRingedList(const T& l_init_value);

	void Initialize(const T& l_init_value);
	**/

	//Maybe make it private in Insert implementation
	void PushFront(const T& l_value);
	void PushBack(const T& l_value);

	void PopBack();
	void PopFront();

	void Insert(const int l_index, const T& l_value);
	void Remove(const int l_index);
	void Clear();

	T Front();
	T Back();

	int GetSize();
private:
	std::shared_ptr<SingleListNode<T>> m_head_node;
	std::shared_ptr<SingleListNode<T>> m_tail_node;

	int m_size = 0;
};

/**
//Edited
template<typename T>
CustomSingleRingedList<T>::CustomSingleRingedList(const T& l_init_value)
{
	Initialize(l_init_value);
}

//Edited
template<typename T>
void CustomSingleRingedList<T>::Initialize(const T& l_init_value)
{
	if (m_size > 1)
	{
		throw std::exception("Initializing already initialized single linked list exception.");
	}

	m_head_node = std::make_shared<SingleListNode<T>>(l_init_value);
	m_tail_node = m_head_node;

	m_head_node->m_next_node = m_tail_node;
	m_tail_node->m_next_node = m_head_node;

	m_size = 1;
}
**/

//Edited
template<typename T>
void CustomSingleRingedList<T>::PushFront(const T& l_value)
{
	m_size++;

	if (m_size == 1)
	{
		m_head_node = std::make_shared<SingleListNode<T>>(l_value);
		m_tail_node = m_head_node;

		m_head_node->m_next_node = m_tail_node;
		m_tail_node->m_next_node = m_head_node;

		return;
	}

	auto new_node = std::make_shared<SingleListNode<T>>(l_value);

	new_node->m_next_node = m_head_node;
	m_head_node = new_node;
	m_tail_node->m_next_node = m_head_node;

}

//Edited
template<typename T>
void CustomSingleRingedList<T>::PushBack(const T& l_value)
{
	m_size++;

	if (m_size == 1)
	{
		m_head_node = std::make_shared<SingleListNode<T>>(l_value);
		m_tail_node = m_head_node;

		m_head_node->m_next_node = m_tail_node;
		m_tail_node->m_next_node = m_head_node;

		return;
	}

	auto new_node = std::make_shared<SingleListNode<T>>(l_value);

	m_tail_node->m_next_node = new_node;
	m_tail_node = new_node;
	m_tail_node->m_next_node = m_head_node;

	
}

//TO EDIT
template<typename T>
void CustomSingleRingedList<T>::PopBack()
{
	if (m_size < 1)
	{
		throw std::exception("PopBack from empty array exception.");
	}
	
	m_size--;

	if (m_size == 0)
	{
		m_head_node = nullptr;
		//m_tail_node = nullptr;

		return;
	}

	auto iter_node = m_head_node;
	while (iter_node->m_next_node != m_tail_node)
	{
		iter_node = iter_node->m_next_node;
	}
	iter_node->m_next_node = m_head_node;
	m_tail_node = iter_node;
}

//Edited
template<typename T>
void CustomSingleRingedList<T>::PopFront()
{
	if (m_size < 1)
	{
		throw std::exception("PopFront from empty array exception.");
	}

	
	m_head_node = (m_size == 1) ? nullptr : m_head_node->m_next_node;
	if (m_head_node == nullptr)
	{
		m_tail_node = m_head_node;
	}
	else
	{
		m_tail_node->m_next_node = m_head_node;
	}
	m_size--;
}

//Edited
template<typename T>
void CustomSingleRingedList<T>::Insert(const int l_index, const T& l_value)
{
	if (l_index > m_size || l_index < 0)
	{
		throw std::exception("Index out of bounds exception.");
	}

	if (l_index == 0)
	{
		PushFront(l_value);
		return;
	}
	else if (l_index == m_size)
	{
		PushBack(l_value);
		return;
	}

	auto prev_index_node = m_head_node;
	for (int counter = 0; counter < (l_index - 1); counter++)
	{
		prev_index_node = prev_index_node->m_next_node;
	}

	auto new_node = std::make_shared<SingleListNode<T>>(l_value);
	new_node->m_next_node = prev_index_node->m_next_node;
	prev_index_node->m_next_node = new_node;

	m_size++;
}

//Edited
template<typename T>
void CustomSingleRingedList<T>::Remove(const int l_index)
{
	if (l_index >= m_size || l_index < 0)
	{
		throw std::exception("Index out of bounds exception.");
	}

	
	if (l_index == m_size - 1)
	{
		PopBack();
		return;
	}
	else if (l_index == 0)
	{
		PopFront();
		return;
	}

	auto iter_node = m_head_node;
	for (int counter = 0; counter < (l_index - 1); counter++)
	{
		iter_node = iter_node->m_next_node;
	}
	iter_node->m_next_node = iter_node->m_next_node->m_next_node;

	m_size--;
}

//Edited
template<typename T>
void CustomSingleRingedList<T>::Clear()
{
	if (m_size < 1)
	{
		throw std::exception("Clearing empty list exception.");
	}

	while (m_head_node != nullptr || m_tail_node != nullptr)
	{
		this->PopFront();
	}
}

template<typename T>
T CustomSingleRingedList<T>::Front()
{
	if (m_size < 1)
	{
		throw std::exception("Access to element of empty list exception.");
	}

	return m_head_node->m_value;
}

template<typename T>
T CustomSingleRingedList<T>::Back()
{
	if (m_size < 1)
	{
		throw std::exception("Access to element of empty list exception.");
	}

	return m_tail_node->m_value;
}

template<typename T>
int CustomSingleRingedList<T>::GetSize()
{
	return m_size;
}

