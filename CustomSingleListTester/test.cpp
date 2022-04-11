#include "pch.h"

#include "../CustomSingleList/CustomSingleList.h"
#include "../CustomSingleList/CustomSingleRingedList.h"
#include "../CustomSingleList/CustomSingleRingedListV2.h"

#include <string>

/**
TEST(CustomSingleListIntTestCase, ComparisonTest)
{
	CustomSingleList<int> single_list_1;
	single_list_1.PushBack(1);
	single_list_1.PushBack(3);
	single_list_1.PushBack(2);

	CustomSingleList<int> single_list_2 = { 1, 3, 2 };
	EXPECT_TRUE(single_list_1 == single_list_2);

	EXPECT_EQ(single_list_1.Front(), 1);
	EXPECT_EQ(single_list_1.Back(), 2);
	EXPECT_EQ(single_list_1.GetSize(), 3);
}
**/

TEST(CustomSingleListIntTestCase, InitializationTest)
{
	CustomSingleList<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = {1, 3, 2};
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomSingleListIntTestCase, FrontTest)
{
	CustomSingleList<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleListIntTestCase, BackTest)
{
	CustomSingleList<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleListIntTestCase, PushFrontTest)
{
	CustomSingleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ second_value, first_value }));
}

TEST(CustomSingleListIntTestCase, PushBackTest)
{
	CustomSingleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, second_value }));
}

TEST(CustomSingleListIntTestCase, PopFrontTest)
{
	CustomSingleList<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopFront from empty array exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleList<int>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomSingleList<int>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListIntTestCase, PopBackTest)
{
	CustomSingleList<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopBack from empty array exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleList<int>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListIntTestCase, ClearTest)
{
	CustomSingleList<int> single_list;

	const int value = 25;

	const int list_size = 4;
	
	single_list = CustomSingleList<int>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListIntTestCase, InsertTest)
{
	CustomSingleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, first_value, second_value }));
}

TEST(CustomSingleListIntTestCase, RemoveTest)
{
	CustomSingleList<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleList<int>({first_value, first_value, second_value});

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value}));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListIntTestCase, ReFillingTest)
{
	CustomSingleList<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed int list tests


TEST(CustomSingleRingedListIntTestCase, InitializationTest)
{
	CustomSingleRingedListV2<int> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { 1, 3, 2 };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomSingleRingedListIntTestCase, FrontTest)
{
	CustomSingleRingedListV2<int> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleRingedListIntTestCase, BackTest)
{
	CustomSingleRingedListV2<int> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleRingedListIntTestCase, PushFrontTest)
{
	CustomSingleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ second_value, first_value }));
}

TEST(CustomSingleRingedListIntTestCase, PushBackTest)
{
	CustomSingleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, second_value }));
}

TEST(CustomSingleRingedListIntTestCase, PopFrontTest)
{
	CustomSingleRingedListV2<int> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopFront from empty array exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleRingedListV2<int>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<int>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListIntTestCase, PopBackTest)
{
	CustomSingleRingedListV2<int> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopBack from empty array exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleRingedListV2<int>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<int>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListIntTestCase, ClearTest)
{
	CustomSingleRingedListV2<int> single_list;

	const int value = 25;

	const int list_size = 4;

	single_list = CustomSingleRingedListV2<int>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListIntTestCase, InsertTest)
{
	CustomSingleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<int>({ first_value, first_value, second_value }));
}

TEST(CustomSingleRingedListIntTestCase, RemoveTest)
{
	CustomSingleRingedListV2<int> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	const int first_value = 25;
	const int second_value = 43;

	single_list = CustomSingleRingedListV2<int>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<int>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<int>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListIntTestCase, ReFillingTest)
{
	CustomSingleRingedListV2<int> single_list;

	const int first_value = 25;
	const int second_value = 43;

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//String Test Part


TEST(CustomSingleListStringTestCase, InitializationTest)
{
	CustomSingleList<std::string> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { "1", "3", "2" };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomSingleListStringTestCase, FrontTest)
{
	CustomSingleList<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleListStringTestCase, BackTest)
{
	CustomSingleList<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleListStringTestCase, PushFrontTest)
{
	CustomSingleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ second_value, first_value }));
}

TEST(CustomSingleListStringTestCase, PushBackTest)
{
	CustomSingleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value, second_value }));
}

TEST(CustomSingleListStringTestCase, PopFrontTest)
{
	CustomSingleList<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopFront from empty array exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleList<std::string>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListStringTestCase, PopBackTest)
{
	CustomSingleList<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopBack from empty array exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleList<std::string>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListStringTestCase, ClearTest)
{
	CustomSingleList<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;

	single_list = CustomSingleList<std::string>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListStringTestCase, InsertTest)
{
	CustomSingleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value, first_value, second_value }));
}

TEST(CustomSingleListStringTestCase, RemoveTest)
{
	CustomSingleList<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleList<std::string>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomSingleList<std::string>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleListStringTestCase, ReFillingTest)
{
	CustomSingleList<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}


//Ringed string list tests


TEST(CustomSingleRingedListStringTestCase, InitializationTest)
{
	CustomSingleRingedListV2<std::string> single_list;
	EXPECT_EQ(single_list.GetSize(), 0);

	single_list = { "1", "3", "2" };
	EXPECT_EQ(single_list.GetSize(), 3);
}

TEST(CustomSingleRingedListStringTestCase, FrontTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	try
	{
		single_list.Front();
		FAIL() << "Front() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { second_value };

	EXPECT_EQ(single_list.Front(), second_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleRingedListStringTestCase, BackTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	try
	{
		single_list.Back();
		FAIL() << "Back() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Access to element of empty list exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = { first_value, second_value };

	EXPECT_EQ(single_list.Back(), second_value);
	EXPECT_EQ(single_list.GetSize(), 2);

	single_list = { first_value };

	EXPECT_EQ(single_list.Back(), first_value);
	EXPECT_EQ(single_list.GetSize(), 1);
}

TEST(CustomSingleRingedListStringTestCase, PushFrontTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushFront(first_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value }));

	single_list.PushFront(second_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ second_value, first_value }));
}

TEST(CustomSingleRingedListStringTestCase, PushBackTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.PushBack(first_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value }));

	single_list.PushBack(second_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value, second_value }));
}

TEST(CustomSingleRingedListStringTestCase, PopFrontTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopFront();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopFront from empty array exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleRingedListV2<std::string>({ first_value, second_value });

	single_list.PopFront();
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ second_value }));

	single_list.PopFront();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListStringTestCase, PopBackTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	try
	{
		single_list.PopBack();
		FAIL() << "PopFront() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "PopBack from empty array exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleRingedListV2<std::string>({ first_value, second_value });

	single_list.PopBack();
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value }));

	single_list.PopBack();
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListStringTestCase, ClearTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	const std::string value = "25";

	const int list_size = 4;

	single_list = CustomSingleRingedListV2<std::string>({ value, value, value, value });
	EXPECT_EQ(single_list.GetSize(), list_size);

	single_list.Clear();

	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListStringTestCase, InsertTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	try
	{
		single_list.Insert(-1, first_value);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	single_list.Insert(0, first_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value }));

	single_list.Insert(single_list.GetSize(), second_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value, second_value }));

	single_list.Insert(single_list.GetSize() - 1, first_value);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value, first_value, second_value }));
}

TEST(CustomSingleRingedListStringTestCase, RemoveTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	try
	{
		single_list.Remove(-1);
		FAIL() << "Insert() should fail with empty array";
	}
	catch (const std::exception& e)
	{
		EXPECT_EQ(std::string(e.what()), "Index out of bounds exception.");
	}

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list = CustomSingleRingedListV2<std::string>({ first_value, first_value, second_value });

	single_list.Remove(single_list.GetSize() - 2);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value, second_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_TRUE(single_list == CustomSingleRingedListV2<std::string>({ first_value }));

	single_list.Remove(single_list.GetSize() - 1);
	EXPECT_EQ(single_list.GetSize(), 0);
}

TEST(CustomSingleRingedListStringTestCase, ReFillingTest)
{
	CustomSingleRingedListV2<std::string> single_list;

	const std::string first_value = "25";
	const std::string second_value = "43";

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	single_list.Remove(single_list.GetSize() - 2);
	single_list.Remove(single_list.GetSize() - 1);
	single_list.Remove(single_list.GetSize() - 1);

	single_list.Insert(0, first_value);
	single_list.Insert(single_list.GetSize(), second_value);
	single_list.Insert(single_list.GetSize() - 1, first_value);

	EXPECT_EQ(single_list.GetSize(), 3);
	EXPECT_EQ(single_list.Front(), first_value);
	EXPECT_EQ(single_list.Back(), second_value);
}
