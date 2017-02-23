//MThreadStorage.h
#include "boost/shared_ptr.hpp"
#include "BasicModule/MLog.h" 

template<typename T, int ALLOC_BLOCK_SIZE = 50>
class MThreadStorage {
public:
	explicit ThreadStorage() {
		allocBlock();
	}

	boost::shared_ptr<T> getInstance() {
		if(sizeof(char*) > sizeof(T))
			MLog::criticalLog("MThreadStorage.h getInstance()");

		if (_freePointer == NULL) {
			allocBlock();
		}

		char* returnPointer = _freePointer;

		_freePointer = *((char**)returnPointer);

		return boost::shared_ptr<T>((T*)returnPointer, ThreadStorage<T, ALLOC_BLOCK_SIZE>());
	}

	//Destruction function
	void operator () (T* deletedPointer) {
		*((char**)deletedPointer) = _freePointer;
		_freePointer = (char*)deletedPointer;
	}
private:
	void allocBlock() {
		_freePointer = new char[sizeof(T) * ALLOC_BLOCK_SIZE];

		char** current = (char**)_freePointer;
		char* next = _freePointer;

		for (int i = 0; i < ALLOC_BLOCK_SIZE - 1; i++) {
			next += sizeof(T);
			*current = next;
			current = (char**)next;
		}

		*current = NULL;
	}

	char* _freePointer;
};
