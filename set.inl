#include "set.h"
#include "setiterator.inl"

//constructors and destructor
template<typename T>
coursework::Set<T>::Set() : head(nullptr), sz(0) {}

template<typename T>
coursework::Set<T>::Set(const T& value)
{
	sz++;
	head = new node(value, true);
}

template<typename T>
coursework::Set<T>::Set(const std::initializer_list<T>& init_list)
{
	insetr(init_list);
}

template<typename T>
coursework::Set<T>::~Set()
{
	_destroy_tree(head);
}

//public methots
template<typename T>
void coursework::Set<T>::insetr(const std::initializer_list<T>& init_list)
{
	for (T el : init_list)
		insetr(el);
}

template<typename T>
bool coursework::Set<T>::empty()
{
	return sz == 0;
}

template<typename T>
bool coursework::Set<T>::erase(const T& value)
{
	node* temp_nd = _find_nd(value);
	if (!temp_nd)
		return false;

	coursework::Set<T>* temp = new coursework::Set<T>;
	_fill_tm_set(head, temp, value);

	_destroy_tree(head);
	head = temp->head;
}

//private methots
template<typename T>
void coursework::Set<T>::_destroy_tree(node* nd)
{
	if (!nd)
		return;

	_destroy_tree(nd->left);
	nd->left = nullptr;
	_destroy_tree(nd->right);
	nd->right = nullptr;
	delete nd;
	nd = nullptr;
	sz--;
}

template<typename T>
void coursework::Set<T>::_fill_tm_set(node* nd, Set<T>* tm_set, const T& whithout_el)
{
	if (!nd)
		return;
	_fill_tm_set(nd->left, tm_set, whithout_el);
	if(nd->data != whithout_el)
		tm_set->insetr(nd->data);
	_fill_tm_set(nd->right, tm_set, whithout_el);
}

