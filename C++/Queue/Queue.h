
#ifndef QUEUE_H_
#define QUEUE_H_


template <class T>
class Queue{
	int size;
	int front, rear;
	T* array;
	int count;

public:
	Queue(int=10);
	T first();
	T last();
	void enqueue(T&);
	T dequeue();
	bool isEmpty();
	bool isFull();
	void destroy();
	~Queue();

};
//initializing an empty queue
template <class T>
Queue<T>::Queue(int size){
	this->size = size;
	front = 0;
	rear = size - 1;
	count = 0;
	array = new T[size];
}

template <class T>
void Queue<T>::destroy(){
	front = count = 0;
	rear = size-1;
}
template <class T>
bool Queue<T>::isEmpty(){
	return count==0;
}

template <class T>
bool Queue<T>::isFull(){
	return count==size;
}

template <class T>
T Queue<T>::first(){
	if(!isEmpty()){
		return array[front];
	}
}
template <class T>
T Queue<T>::last(){
	if(!isEmpty()){
		return array[rear];
	}
}
template <class T>
void Queue<T>::enqueue(T& item){
	if(!isFull()){
		rear = (rear+1) % size;
		array[rear] = item;
		count++;
	}
}

template <class T>
T Queue<T>::dequeue(){
	if(!isEmpty()){
		T item = array[front];
		front = (front+1) % size;
		count--;
		return item;
	}
}

template <class T>
Queue<T>::~Queue(){
	delete[] array;
}


#endif /* QUEUE_H_ */
