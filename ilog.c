
#include "ilog.h"

int set_and_get_logfile(char* _filename,bool _set)
{
  static char file[256];
  int n,flag;
  FILE *log;
  if (_set){
     strcpy(file,_filename);
     strcat(file,".log");
     log=fopen(file,"w");
     fclose(log);
  }
  n=strlen(file);
  flag=0;
  if (n!=0 && n<=256)
  {
     if (file[n-1]=='g' && file[n-2]=='o' && file[n-3]=='l')
        flag=1;
  }
  if (!flag){
    strcpy(file,"logfile");
    set_and_get_logfile(file,true);
  }
 strcpy(_filename,file);
return 0;
}


int log_message(char * _message, bool _set)
{
  static char message[1024];
  char file[256];
  FILE *log;
  set_and_get_logfile(file,false);
  if (_set){
     strcpy(message,_message);
     log=fopen(file,"a");
     fprintf(log,"%s\n",_message);
     fclose(log);
  }
  else
    strcpy(_message,message);
return 0;
}

int get_logmessage(char *_message)
{
    log_message(_message, false);
return EXIT_SUCCESS;
}

int set_logmessage(char *_message)
{
    log_message(_message, true);
return EXIT_SUCCESS;
}


int get_logfile(char *_file)
{
    set_and_get_logfile(_file,false);
return EXIT_SUCCESS;
}

int set_logfile(char *_file)
{
    set_and_get_logfile(_file,true);
return EXIT_SUCCESS;
}


void LogPrintf(char *buff,...)
{
    char Status[1024];
    FILE *log;
    char file[256];
    va_list arglist;
    va_start(arglist,buff);
    vsprintf(Status,buff,arglist);
    va_end(arglist);
    set_and_get_logfile(file,false);
    log=fopen(file,"a");
    fprintf(log,"%s",Status);
    fclose(log);
}



