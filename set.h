#pragma once

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
		};
		node* tree;
		size_t size;
	public:
		Set() : tree(nullptr), size(0) {};
		~Set() {};
	public:
		class Iterator
		{
		private:
			const T* ptr_data;
		public:
			Iterator(): ptr_data(nullptr) {};
			~Iterator() {};
		public:
			
		};
	public:
	};

	
}