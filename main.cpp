#include <iostream>
#include "set.h"
#include "set.inl"

int main(void)
{
	coursework::Set<int> a2{ 1, 4 };
	a2.insetr({3, 5, 6});  // ������ insert
	coursework::Set<int>::Iterator it2 = a2.begin(); // ������ .begin()

	for (; it2 != a2.end(); it2++) // ������ ���������, ���������� �� ��������� + .end()
		std::cout << *it2 << ' '; // ������ ������������� ���������
	std::cout << std::endl;

	it2 = a2.find(4); // ������ find()
	if (it2 != a2.end())
		std::cout << "el = " << *it2 << " found" << std::endl;
	else
		std::cout << "el not found" << std::endl;

	it2 = a2.find(7);
	if (it2 != a2.end())
		std::cout << "el = " << *it2 << " found" << std::endl;
	else
		std::cout << "el not found" << std::endl;

	std::cout << a2.count(4) << std::endl; // ������ count()
	std::cout << a2.count(7) << std::endl;

	std::cout << "is set empty? = " << a2.empty() << std::endl; // ������ empty()

	a2.erase(7); // ������ erase()
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