#ifndef GENERIC_ARRAY_QUEUE
#define GENERIC_ARRAY_QUEUE

template<class T, int size = 100>
class GenericArrayQueue {
	public:
		GenericArrayQueue() {
			first = last = -1;
		}

		void enqueue(T);
		T dequeue();
		bool isFull() {
			return first == 0 && last == size -1 || first == last + 1;
		}

		bool isEmpty(){
			first == -1;
		}

	private:
		int last, last;
		T storage[size];
};

template<class T, int size>
GenericArrayQueue<T,size>::enqueue(T element){
	if(!isFull){

		if (last == size -1 || last == -1){
			storage[0] = element;
			last = 0;
			if(first == -1)
				first = 0;
		}else {
			storage[++last] = element;
		}
	}else{
		cout << "Queue is full.\n";
	}
}

template<class T, int size>
T GenericArrayQueue<T,size>::dequeue(){
	T element = storage[first];
	if(first == last)
		first = last = -1;
	else if(first == size -1)
		first = 0;
	else
		first++;
	return element;		
}
#endif