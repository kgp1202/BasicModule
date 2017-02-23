//MCircularQueue.h

#include <string.h>

template<class T, int MAX_QUEUE_SIZE = 50>
class MCircularQueue{
public:
	MCircularQueue();
	~MCircularQueue();
private:
	T _queue[MAX_QUEUE_SIZE];
	int _head;
	int _tail;
public:
	bool begin();
	bool end();
	bool push(T);
	bool pop(T&);
	bool isEmpty();
};

template<class T, int MAX_QUEUE_SIZE>
MCircularQueue<T, MAX_QUEUE_SIZE>::MCircularQueue(){
	begin();
}

template<class T, int MAX_QUEUE_SIZE>
MCircularQueue<T, MAX_QUEUE_SIZE>::~MCircularQueue(){
	
}

template<class T, int MAX_QUEUE_SIZE>
bool MCircularQueue<T, MAX_QUEUE_SIZE>::begin(){
	memset(&_queue, 0, sizeof(T) * MAX_QUEUE_SIZE);
	_head = _tail = 0;

	return true;
}

template<class T, int MAX_QUEUE_SIZE>
bool MCircularQueue<T, MAX_QUEUE_SIZE>::end(){
	return true;
}

template<class T, int MAX_QUEUE_SIZE>
bool MCircularQueue<T, MAX_QUEUE_SIZE>::push(T data){
	int nextTail = (_tail + 1) % MAX_QUEUE_SIZE;

	if(nextTail == _head){
		return false;
	}

	memcpy(&_queue[nextTail], &data, sizeof(T));
	_tail = nextTail;
	
	return true;
}

template<class T, int MAX_QUEUE_SIZE>
bool MCircularQueue<T, MAX_QUEUE_SIZE>::pop(T& data){
	if(_head == _tail){
		return false;
	}

	int nextHead = (_head + 1) % MAX_QUEUE_SIZE;
	memcpy(&data, &_queue[nextHead], sizeof(T));
	_head = nextHead;

	return true;
}

template<class T, int MAX_QUEUE_SIZE>
bool MCircularQueue<T, MAX_QUEUE_SIZE>::isEmpty(){
	if(_head == _tail){
		return true;
	}else{
		return false;
	}
	
}
