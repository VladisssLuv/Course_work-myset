#include <iostream>
#include "set.h"
#include "set.inl"
#include <set>

int main(void)
{
	std::set<int> a{ 5, 6, 7, 1 };
	std::set<int>::iterator it = a.begin();

	coursework::Set<int> a2{ 1, 4 };
	coursework::Set<int>::Iterator it2 = a2.insetr(3);
	a2.insetr({3, 5, 6});
	std::cout << *it2 << std::endl;

	return 0;
}