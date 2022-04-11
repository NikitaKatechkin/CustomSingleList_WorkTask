#include "CustomSingleList.h"
#include "CustomSingleRingedList.h"

#include <iostream>

int main()
{
    CustomSingleRingedList<int> test_list;
    //test_list.Initialize(0);
    test_list.PushBack(0);
    test_list.PushFront(0);
    test_list.PopBack();
    test_list.PopFront();
    //std::cout << test_list.GetSize() << std::endl;
    test_list.Insert(0, 25);
    test_list.Clear();

    return 0;
}