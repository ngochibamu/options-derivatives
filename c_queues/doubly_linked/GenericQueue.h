//*************************GenericQueue.h*****************

#ifndef DOUBLY_LINKED_QUEUE
#define DOUBLY_LINKED_QUEUE


#include <list>

template<class T>
class GenericQueue {
	public:
		GenericQueue(){
		}

		void clear(){
			lst.clear();
		}

		bool isEmpty() const {
			return lst.empty();
		}

		T& front() {
			lst.front();
		}

		void enqueue(T element){
			lst.push_back(element);
		}

		T dequeue(){
			T element = lst.front();
			lst.pop_front();
			return element;
		}

	private:
		list<T> lst;
}
#endif