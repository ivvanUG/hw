#ifndef ILOG_H
#define ILOG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<stdarg.h>
int set_and_get_logfile(char* _filename,bool _set);
int log_message(char * _message, bool set);
int get_logmessage(char *_message);
int set_logmessage(char *_message);
int set_logfile(char *_file);
int get_logfile(char *_file);
void LogPrintf(char *buff,...);



#endif
