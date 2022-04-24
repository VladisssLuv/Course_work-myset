#pragma once

namespace coursework
{
	template<typename T>
	class Set
	{
	private:
		struct node
		{
			T data;
			node* left;
			node* right;
		};
		node* tree;
	public:
		Set() {};
		~Set() {};
	};
}