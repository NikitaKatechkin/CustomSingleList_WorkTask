#pragma once

#include "CustomSingleListNode.h"

#include <initializer_list>

template <typename T>
class CustomSingleList
{
using ListNode = SingleListNode<T>;

public:
	CustomSingleList() = default;
	CustomSingleList(std::initializer_list<T> l_init_list);

	virtual ~CustomSingleList() = default;

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

	friend bool operator==(const CustomSingleList<T>& left_operand, const CustomSingleList<T>& right_operand)
	{
		if (left_operand.m_size != right_operand.m_size)
		{
			return false;
		}

		auto left_element = left_operand.m_head_node;
		auto right_element = right_operand.m_head_node;

		for (int counter = 0; counter < left_operand.m_size; counter++)
		{
			if (left_element->m_value != right_element->m_value)
			{
				return false;
			}

			left_element = left_element->m_next_node;
			right_element = right_element->m_next_node;
		}

		return true;
	}
protected:
	std::shared_ptr<ListNode> m_head_node;
	std::shared_ptr<ListNode> m_tail_node;

	int m_size = 0;
};

template<typename T>
CustomSingleList<T>::CustomSingleList(std::initializer_list<T> l_init_list)
{
	for (auto iter : l_init_list)
	{
		PushBack(iter);
	}
}

template<typename T>
void CustomSingleList<T>::PushFront(const T& l_value)
{

	auto new_node = std::make_shared<ListNode>(l_value);

	if (m_size == 0)
	{
		m_head_node = new_node;
		m_tail_node = m_head_node;
	}
	else
	{
		new_node->m_next_node = m_head_node;
		m_head_node = new_node;
	}
	
	m_size++;
}

template<typename T>
void CustomSingleList<T>::PushBack(const T& l_value)
{
	auto new_node = std::make_shared<ListNode>(l_value);

	if (m_size == 0)
	{
		m_head_node = new_node;
		m_tail_node = m_head_node;
	}
	else
	{
		m_tail_node->m_next_node = new_node;
		m_tail_node = new_node;
	}
	
	m_size++;
}

template<typename T>
void CustomSingleList<T>::PopBack()
{
	if (m_size < 1)
	{
		throw std::exception("PopBack from empty array exception.");
	}


	if (m_size == 1)
	{
		m_head_node = nullptr;
		m_tail_node = nullptr;
	}
	else
	{
		auto iter_node = m_head_node;
		while (iter_node->m_next_node != m_tail_node)
		{
			iter_node = iter_node->m_next_node;
		}
		m_tail_node = iter_node;
		m_tail_node->m_next_node = nullptr;
	}

	m_size--;
}

template<typename T>
void CustomSingleList<T>::PopFront()
{
	if (m_size < 1)
	{
		throw std::exception("PopFront from empty array exception.");
	}

	//m_head_node = (m_size == 1) ? nullptr : m_head_node->m_next_node;

	if (m_size == 1)
	{
		m_head_node = nullptr;
		m_tail_node = nullptr;
	}
	else
	{
		m_head_node = m_head_node->m_next_node;
	}

	m_size--;
}

template<typename T>
void CustomSingleList<T>::Insert(const int l_index, const T& l_value)
{
	if (l_index > m_size || l_index < 0)
	{
		throw std::exception("Index out of bounds exception.");
	}

	if (l_index == 0)
	{
		PushFront(l_value);
	}
	else if (l_index == m_size)
	{
		PushBack(l_value);
	}
	else
	{
		auto prev_index_node = m_head_node;

		for (int counter = 0; counter < (l_index - 1); counter++)
		{
			prev_index_node = prev_index_node->m_next_node;
		}

		auto new_node = std::make_shared<ListNode>(l_value);

		new_node->m_next_node = prev_index_node->m_next_node;
		prev_index_node->m_next_node = new_node;

		m_size++;
	}
}

template<typename T>
void CustomSingleList<T>::Remove(const int l_index)
{
	if (l_index >= m_size || l_index < 0)
	{
		throw std::exception("Index out of bounds exception.");
	}

	if (l_index == m_size - 1)
	{
		PopBack();
	}
	else if (l_index == 0)
	{
		PopFront();
	}
	else
	{
		auto iter_node = m_head_node;
		for (int counter = 0; counter < (l_index - 1); counter++)
		{
			iter_node = iter_node->m_next_node;
		}
		iter_node->m_next_node = iter_node->m_next_node->m_next_node;

		m_size--;
	}
}

template<typename T>
void CustomSingleList<T>::Clear()
{
	/**
	if (m_size < 1)
	{
		throw std::exception("Clearing empty list exception.");
	}
	**/

	while (m_size > 0)
	{
		this->PopFront();
	}
}

template<typename T>
T CustomSingleList<T>::Front()
{
	if (m_size < 1)
	{
		throw std::exception("Access to element of empty list exception.");
	}

	return m_head_node->m_value;
}

template<typename T>
T CustomSingleList<T>::Back()
{
	if (m_size < 1)
	{
		throw std::exception("Access to element of empty list exception.");
	}

	return m_tail_node->m_value;
}

template<typename T>
int CustomSingleList<T>::GetSize()
{
	return m_size;
}
