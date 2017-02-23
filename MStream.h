//MStream.h
#include "MMemoryPool.h"

class MStream : public MMemoryPool<MStream, 30>
{
public:
	MStream();
	~MStream();	
private:
	char* _bufferPointer;
	int _length;
public:
	bool setBuffer(char* buffer);

	bool readInt32(int* data);
//	bool readInt64(uint64_t* data);
	bool readChar(char* data);
	bool readChars(char* data, int length);
	bool readBool(bool* data);
	bool readFloat(float* data);
	bool readDouble(double* data);

	bool writeInt32(int data);
//	bool writeInt64(uint64_t data);
	bool writeChar(char data);
	bool writeChars(char* data, int length);
	bool writeBool(bool data);
	bool writeFloat(float data);
	bool writeDouble(double data);

	int getLength();
};
