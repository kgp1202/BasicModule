//MStream.cpp

#include <string.h>
#include "MStream.h"
 
MStream::MStream(){
	_bufferPointer = NULL;
	_length = 0;
}

MStream::~MStream(){

}

bool MStream::setBuffer(char* buffer){
	if(!buffer){
		return false;
	}

	_bufferPointer = buffer;
	_length = 0;

	return true;
}


bool MStream::readInt32(int* data){
	memcpy(data, _bufferPointer + _length, sizeof(int));
		
	_length += sizeof(int); 
	
	return true;
}

bool MStream::readChar(char* data){
	memcpy(data, _bufferPointer + _length, sizeof(char));
		
	_length += sizeof(char); 
	
	return true;
}

bool MStream::readChars(char* data, int length){
	memcpy(data, _bufferPointer + _length, sizeof(char) * length);
		
	_length += sizeof(char) * length; 
	
	return true;
}

bool MStream::readBool(bool* data){
	memcpy(data, _bufferPointer + _length, sizeof(bool));
		
	_length += sizeof(bool); 
	
	return true;
}

bool MStream::readFloat(float* data){
	memcpy(data, _bufferPointer + _length, sizeof(float));
		
	_length += sizeof(float); 
	
	return true;
}

bool MStream::readDouble(double* data){
	memcpy(data, _bufferPointer + _length, sizeof(double));

	_length += sizeof(double);

	return true;
}



bool MStream::writeInt32(int data){
	memcpy(_bufferPointer + _length, &data, sizeof(int));
	
	_length += sizeof(int);
		
	return true;
}

bool MStream::writeChar(char data){
	memcpy(_bufferPointer + _length, &data, sizeof(char));
	
	_length += sizeof(char);
		
	return true;
}


bool MStream::writeChars(char* data, int length){
	memcpy(_bufferPointer + _length, &data, sizeof(char) * length);
	
	_length += sizeof(char) * length;
		
	return true;
}


bool MStream::writeBool(bool data){
	memcpy(_bufferPointer + _length, &data, sizeof(bool));
	
	_length += sizeof(bool);
		
	return true;
}

bool MStream::writeFloat(float data){
	memcpy(_bufferPointer + _length, &data, sizeof(float));
	
	_length += sizeof(float);
		
	return true;
}

bool MStream::writeDouble(double data){
	memcpy(_bufferPointer + _length, &data, sizeof(double));
	
	_length += sizeof(double);
		
	return true;
}


int MStream::getLength(){
	return _length;
}
