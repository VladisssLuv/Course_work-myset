#include <iostream>
#include "set.h"
#include "set.inl"

int main(void)
{
	coursework::Set<int> a2{ 1, 4 };
	a2.insetr({3, 5, 6});  // работа insert
	coursework::Set<int>::Iterator it2 = a2.begin(); // работа .begin()

	for (; it2 != a2.end(); it2++) // работа итератора, инкремента по итератору + .end()
		std::cout << *it2 << ' '; // работа разыминования оператора
	std::cout << std::endl;

	it2 = a2.find(4); // работа find()
	if (it2 != a2.end())
		std::cout << "el = " << *it2 << " found" << std::endl;
	else
		std::cout << "el not found" << std::endl;

	it2 = a2.find(7);
	if (it2 != a2.end())
		std::cout << "el = " << *it2 << " found" << std::endl;
	else
		std::cout << "el not found" << std::endl;

	std::cout << a2.count(4) << std::endl; // работа count()
	std::cout << a2.count(7) << std::endl;

	std::cout << "is set empty? = " << a2.empty() << std::endl; // работа empty()

	a2.erase(7); // работа erase()
	a2.erase(4);

	it2 = a2.begin();
	for (; it2 != a2.end(); it2++) 
		std::cout << *it2 << ' ';
	std::cout << std::endl;

	a2.erase(1);
	it2 = a2.begin();
	for (; it2 != a2.end(); it2++) 
		std::cout << *it2 << ' '; 
	std::cout << std::endl;

	return 0;
}