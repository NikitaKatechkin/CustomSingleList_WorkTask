#pragma once
#include <memory>

template <typename T>
struct SingleListNode
{
	T m_value;
	std::shared_ptr<SingleListNode<T>> m_next_node = nullptr;

	SingleListNode() = default;
	SingleListNode(const T& l_value);
};

template<typename T>
SingleListNode<T>::SingleListNode(const T& l_value)
{
	m_value = l_value;
	m_next_node = nullptr;
}
