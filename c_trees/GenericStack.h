//**************************GeneralStack.h*******************************
#ifndef STACK
#define STACK

#include <vector>
template<class T, int capacity = 30>
class Stack {

	public:
		Stack() {
			pool.reserve(capacity);
		}

		void clear(){
			pool.clear();
		}

		bool isEmpty() const{
			return pool.empty();
		}

		T& top() const{
			return pool.back();
		}

		bool push(const T& element){
			pool.push_back(element);
		}

		T pop() {
			T element = pool.back();
			pool.pop_back();
			return element;
		}

	private:
		vector<T> pool;
}
#endif