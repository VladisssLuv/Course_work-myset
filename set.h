#pragma once
#include <list>

namespace coursework
{
	template<typename T>
	class Set
	{
	private:
		struct node
		{
			const T data;
			node* left;
			node* right;
			node* parent;

			node(const T& v) : data(v), left(nullptr), right(nullptr), parent(nullptr) {};
		};
		node* head;
		size_t sz;
	public:
		class Iterator;
	public:
		Set();
		Set(const T& value);
		Set(const std::initializer_list<T>& init_list);
		~Set();
	public:
		void insetr(const std::initializer_list<T>& init_list);

		Iterator insetr(const T& value) 
		{
			if (!head)
			{
				sz++;
				head = new node(value);
				Iterator it(head);
				return it;
			}
			node* temp = head;
			while (true)
			{
				if (value < temp->data)
				{
					if (temp->left)
						temp = temp->left;
					else
					{
						sz++;
						temp->left = new node(value); // добавить балансировку
						temp->left->parent = temp;
						return Iterator(temp->left);
					}
				}
				else if (value > temp->data)
				{
					if (temp->right)
						temp = temp->right;
					else
					{
						sz++;
						temp->right = new node(value); // добавить балансировку
						temp->right->parent = temp;
						return Iterator(temp->right);
					}
				}
				else
					return Iterator(temp);
			}
		}
	};
}