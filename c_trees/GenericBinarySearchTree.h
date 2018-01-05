#include <queue>
#include <stack>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE


template<class T>
class BinarySearchNode {

	public:
		BinarySearchNode() {

			left = right = 0;
		}

		BinarySearchNode(const T& data, BinarySearchNode<T> *left = 0, BinarySearchNode<T> *right = 0){
			this.data = data;
			this.left = left;
			this.right = right;
		}
		T data;
		BinarySearchNode<T> *left, *right;
};

