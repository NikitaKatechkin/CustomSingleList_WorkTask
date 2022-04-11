#pragma once

#include "CustomSingleList.h"

template <typename T>
class CustomSingleRingedListV2 : public CustomSingleList<T>
{
public:
	CustomSingleRingedListV2();
	CustomSingleRingedListV2(std::initializer_list<T> l_init_list);
	~CustomSingleRingedListV2() = default;

	void PushFront(const T& l_value);
	void PushBack(const T& l_value);

	void PopBack();
	void PopFront();

	friend bool operator==(const CustomSingleRingedListV2<T>& left_operand, const CustomSingleRingedListV2<T>& right_operand)
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
};

template<typename T>
CustomSingleRingedListV2<T>::CustomSingleRingedListV2() :
	CustomSingleList<T>()
{
}

template<typename T>
CustomSingleRingedListV2<T>::CustomSingleRingedListV2(std::initializer_list<T> l_init_list)
{
	for (auto iter : l_init_list)
	{
		PushBack(iter);
	}
}

//Edited
template<typename T>
void CustomSingleRingedListV2<T>::PushFront(const T& l_value)
{
	CustomSingleList<T>::PushFront(l_value);
	m_tail_node->m_next_node = m_head_node;
}

//Edited
template<typename T>
void CustomSingleRingedListV2<T>::PushBack(const T& l_value)
{
	CustomSingleList<T>::PushBack(l_value);
	m_tail_node->m_next_node = m_head_node;
}

//TO EDIT
template<typename T>
void CustomSingleRingedListV2<T>::PopBack()
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
		iter_node->m_next_node = m_head_node;
		m_tail_node = iter_node;
	}

	m_size--;
}

//Edited
template<typename T>
void CustomSingleRingedListV2<T>::PopFront()
{
	if (m_size < 1)
	{
		throw std::exception("PopFront from empty array exception.");
	}


	if (m_size == 1)
	{
		m_head_node = nullptr;
		m_tail_node = nullptr;
	}
	else
	{
		m_head_node = m_head_node->m_next_node;
		m_tail_node->m_next_node = m_head_node;
	}
	m_size--;
}
