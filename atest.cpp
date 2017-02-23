#include <iostream>
#include <stdio.h>
#include "MLog.h"

int main(){
	int errono = 3;
	MLog::writeLog("THIS IS FIRST errorno = %d\n", errono);
	
	MLog::criticalLog("THIS IS FIRST errorno = %d\n", errono);
	
}
