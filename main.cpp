#include <iostream>
#include "List.cpp"

int main()
{
	List<int> test;
	int a = 15;
	test.PushFront(a);
	test.PushFront(34);
	test.PushFront(45);
	test.PushFront(121);
	test.PushFront(25);
	List<int>::Iterator iter = test.Begin();
	for(;iter != test.End(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;

	iter = test.End();
	iter--;
	for(;iter != test.Begin(); --iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;

	iter = test.RBegin();
	for(;iter != test.REnd(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;

	iter = test.Begin();
	iter++;
	test.Erase(iter);
	iter = test.Begin();
	for(;iter != test.End(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;

	iter = test.Begin();
	iter++;
	test.InsertLeft(iter, 4444);
	iter++;
	test.InsertRight(iter, 4444);
	test.Insert(iter, 4444);
	iter = test.Begin();
	for(;iter != test.End(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;

	test.Clear();
	iter = test.Begin();
	for(;iter != test.End(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
