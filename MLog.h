//MLog.h

#pragma once

class MLog{
public:
	static void writeLog(const char* data, ...);
	static void criticalLog(const char* data, ...);
	static void setLogFile();
	static void setLogFile(const char* path);
private:
	static int logFD;
};
