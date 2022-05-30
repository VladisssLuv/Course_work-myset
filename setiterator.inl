#include"set.h"

template<typename T>
class coursework::Set<T>::Iterator
{
private:
	node* nd;
public:
	Iterator();
	Iterator(node* nd_n);
	Iterator(const Iterator& it);
	~Iterator();
public:
	Iterator& operator=(const Iterator& it) 
	{
		if (this == &it)
		{
			return *this;
		}
		nd = it.nd;
		return *this;
	};
	const T& operator*() const;
	bool operator==(const Iterator& right) const;

	Iterator& operator++()
	{
		nd = _inc_tree(nd);
		return *this;
	}

	Iterator& operator++(int)
	{
		Iterator temp(nd);
		nd = _inc_tree(nd);
		return temp;
	}
private:
	node* _inc_tree(node* nd) // дописать
	{
		return nd;
	}
};

template<typename T>
coursework::Set<T>::Iterator::Iterator() : nd(nullptr) {};

template<typename T>
coursework::Set<T>::Iterator::Iterator(node* nd_n) : nd(nd_n) {};

template<typename T>
coursework::Set<T>::Iterator::Iterator(const Iterator& it) : nd(it.nd) {};

template<typename T>
coursework::Set<T>::Iterator::~Iterator() {};

template<typename T>
const T& coursework::Set<T>::Iterator::operator*() const
{
	return nd->data;
}

template<typename T>
bool coursework::Set<T>::Iterator::operator==(const coursework::Set<T>::Iterator& right) const
{
	return nd->data == right.nd->data;
}
