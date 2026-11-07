#include <stdio.h>
#include <syslog.h>



int main(int argc, char *argv[]){
	openlog("assignment2writerlog", LOG_PID, LOG_USER);
	if(2 != argc-1){
		printf("Error: The number of arguments must be 2\n");
		syslog(LOG_ERR, "The number of argument must be 2");
		return 1;
	}
	FILE* fptr;
	fptr = fopen(argv[1], "w");
	if(NULL == fptr){
		printf("Error: file %s cannot be open\n", argv[1]);
		syslog(LOG_ERR, "File %s cannot be open", argv[1]);
		return 1;
	}
	syslog(LOG_INFO, "File %s was open successfully", argv[1]);
	fputs(argv[2], fptr);
	fputs("\n", fptr);
	syslog(LOG_INFO, "The string %s was written into the file %s", argv[2], argv[1]);
	fclose(fptr);
	syslog(LOG_INFO, "File %s was closed", argv[1]);
	return 0;
} 
