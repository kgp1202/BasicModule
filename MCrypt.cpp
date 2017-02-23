//MCrypt.cpp
#include "MCrypt.h"
#include <string.h>

bool MCrypt::encrypt(const char* src, char* des, int length){
	memcpy(des, src, length);

	return true;
}

bool MCrypt::decrypt(const char* src, char* des, int length){
	memcpy(des, src, length);

	return true;
}
