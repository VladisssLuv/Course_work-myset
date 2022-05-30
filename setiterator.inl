#include"set.h"

template<typename T>
class coursework::Set<T>::Iterator
{
private:
	node* nd;
public:
	Iterator() : nd(nullptr) {};
	Iterator(node* nd_n) : nd(nd_n) {};
	Iterator(const Iterator& it) : nd(it.nd) {};
	~Iterator() {};
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
	const T& operator*() const { return nd->data; } ;
	bool operator==(const Iterator& right) const 
	{ 
		if (nd != nullptr && right.nd != nullptr)
			return nd->data == right.nd->data;
		else if (nd == nullptr && right.nd == nullptr)
			return true;
		else
			return false;
	} 
	bool operator!=(const Iterator& right) const 
	{
		if (nd != nullptr && right.nd != nullptr)
			return nd->data != right.nd->data;
		else if (nd == nullptr && right.nd == nullptr)
			return false;
		else
			return true;
	}

	Iterator& operator++()
	{
		_inc_tree();
		return *this;
	}

	Iterator& operator++(int)
	{
		Iterator temp(nd);
		_inc_tree();
		return temp;
	}
private:
	void _inc_tree();
	node* _lefter(node* nd)
	{
		node* temp = nd;
		while (temp->left)
			temp = temp->left;
		return temp;
	}
};

//private methots
template<typename T>
void coursework::Set<T>::Iterator::_inc_tree()
{
	if(nd->is_left)
	{
		if (nd->right)
			nd = _lefter(nd->right);
		else if (nd->parent)
			nd = nd->parent;
		else
			nd = nullptr;
	}
	else
	{
		if (nd->right)
			nd = _lefter(nd->right);
		else if (nd->parent->is_left)
			nd = nd->parent->parent;
		else
		{
			node* temp = nd;
			while (!temp->parent->is_left)
				temp = temp->parent;
			nd = temp->parent->parent;
		}
	}
}
