#include "MLog.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int MLog::logFD;

void MLog::writeLog(const char* data, ...){
	if(logFD == 0){
		setLogFile();
	}

	va_list	arg, copy;

	va_start(arg, data);
	va_copy(copy, arg);

	vprintf(data, arg);
	vdprintf(logFD, data, copy);

	va_end(arg);
	va_end(copy);
	
	return;
}

void MLog::criticalLog(const char* data, ...){
	perror("CRITICAL");

	if(logFD == 0){
		setLogFile();
	}

	va_list	arg, copy;

	va_start(arg, data);
	va_copy(copy, arg);

	dprintf(logFD, "Critical\n");
	vdprintf(logFD, data, arg);

	printf("Critical\n");
	vprintf(data, copy);

	va_end(arg);
	va_end(copy);
	
	exit(-1);

	return;
}

void MLog::setLogFile(){
	setLogFile("./Log.log");
}

void MLog::setLogFile(const char* path){
	logFD = open(path, O_WRONLY | O_APPEND | O_CREAT, 0777);
	if(logFD <= 0){
		printf("Fail to setLogFile()\n");
		exit(-1);
	}	
}

