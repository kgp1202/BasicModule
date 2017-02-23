//MCrypt.h
#pragma once

class MCrypt{
public:
	static bool encrypt(const char* src, char* des, int length); 
	static bool decrypt(const char* src, char* des, int length);
};
