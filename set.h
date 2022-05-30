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
			bool is_left;

			node(const T& v, bool flag) : data(v), is_left(flag), left(nullptr), right(nullptr), parent(nullptr) {};
		};
		node* head;
		size_t sz;
	public:
		class Iterator; // in setiterator.inl
	public:
		Set(); // in set.inl
		Set(const T& value); // in set.inl
		Set(const std::initializer_list<T>& init_list); // in set.inl
		~Set(); // in set.inl
	public:
		void insetr(const std::initializer_list<T>& init_list); // in set.inl

		bool empty(); // in set.inl

		Iterator insetr(const T& value) 
		{
			if (!head)
			{
				sz++;
				head = new node(value, true);
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
						temp->left = new node(value, true); 
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
						temp->right = new node(value, false);
						temp->right->parent = temp;
						return Iterator(temp->right);
					}
				}
				else
					return Iterator(temp);
			}
		}

		bool erase(const T& value); // in set.inl

		Iterator begin() const 
		{
			if (!head)
				return Iterator();

			node* temp = head;
			while (head->left)
				temp = head->left;
			return Iterator(temp);
		};

		Iterator end() const
		{
			return Iterator();
		}

		Iterator find(const T& value) const 
		{
			return Iterator(_find_nd(value));
		}

		size_t count(const T& value) const
		{
			if (_find_nd(value))
				return 1;
			else
				return 0;
		}

	private:
		void _destroy_tree(node* nd); // in set.inl
		void _fill_tm_set(node* nd, Set<T>* tm_set, const T& whithout_el); // in set.inl
		
		node* _find_nd(const T& value) const
		{
			node* temp = head;
			while(true)
			{
				if (!temp)
					return nullptr;
				if (value < temp->data)
					temp = temp->left;
				else if (value > temp->data)
					temp = temp->right;
				else if (value == temp->data)
					return temp;
			}
		}
	};
}