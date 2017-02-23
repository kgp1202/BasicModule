//MMemoryPool.h

#pragma once

#include <iostream>
#include <assert.h>
#include <stdlib.h>

template<class T, int ALLOC_BLOCK_SIZE = 50>
class MMemoryPool{
public:
	static void* operator new(std::size_t allocLength){
		assert(sizeof(T) == allocLength);
		assert(sizeof(T) >= sizeof(char*));

		if(!_freePointer){
			allocBlock();
		}

		char* returnPointer = _freePointer;
		
		_freePointer = *((char**)returnPointer);

		return returnPointer;
	}
	static void operator delete(void* deletedPointer){
		 *((char**)deletedPointer) = _freePointer;

		_freePointer = (char*)deletedPointer;
	}
private:
	static void allocBlock(){
		_freePointer = new char[sizeof(T) * ALLOC_BLOCK_SIZE];

		char** current = (char**)_freePointer;
		char* next = _freePointer;

		for(int i = 0; i < ALLOC_BLOCK_SIZE - 1; i++){
			next += sizeof(T);
			*current = next;
			current = (char**)next;
		}
	
		*current = NULL;
	}
private:
	static char* _freePointer;
protected:
	~MMemoryPool(){}
};

template<class T, int ALLOC_BLOCK_SIZE>
char* MMemoryPool<T, ALLOC_BLOCK_SIZE>::_freePointer;
