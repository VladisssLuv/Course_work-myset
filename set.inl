#include "set.h"
#include "setiterator.inl"

template<typename T>
coursework::Set<T>::Set() : head(nullptr), sz(0) {}

template<typename T>
coursework::Set<T>::~Set(){} //допсать

template<typename T>
coursework::Set<T>::Set(const T& value)
{
	sz++;
	head = new node(value);
}

template<typename T>
coursework::Set<T>::Set(const std::initializer_list<T>& init_list)
{
	insetr(init_list);
}

template<typename T>
void coursework::Set<T>::insetr(const std::initializer_list<T>& init_list)
{
	for (T el : init_list)
		insetr(el);
}
