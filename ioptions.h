#ifndef IOPTIONS_H
#define IOPTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ilog.h"


#define MAXOPTIONS 100

typedef struct{
  char option[128]; ///Option names, such as: -basicfile or something
  char opttype; /// if 's' it expects for a string, 'd' expects for a double, 'i' expects for an integer type, 'n' expects for nothing, 'j' integer vector, 'f' double vector
  bool set; ///If the option has been set by the user
  double dvalue; ///If the option is of type double, the option value is stored here
  int ivalue; ///If the option is of type integer, the option value is stored here
  int order; ///The correspongin index in the option list
  char svalue[256]; ///If the option is of type 'string', then it is stored here
  char vsizeOpt[128];   ///If the option is of type "vector", here is the name of the option which determines the vector size, if the value is '\0',
                        ///then the vector size is fixed according the value in the configuration file
  char shortdescription[101]; ///A short description of the option.
  int *ivector;///If the option is of type 'integer vector' this is used
  double *dvector;///If the option is of type 'integer vector' this is used
  int vsize; ///If the option reads a vector, this is the vector size

}iOptionStruct;

int iOptionCounter(int _counter);
iOptionStruct Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
iOptionStruct* Set_Get_Option2(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
int idefine_new_option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_description, bool _IfSetbyDefault, bool _FirstOption);
iOptionStruct *Get_Option_By_Index(int index);
iOptionStruct Get_Option_By_Name(const char* _option);
int print_options();
int read_options(int argc, const char *argv[]);
int  OptInputFile(int argcO, char **argvO, int *argcT, char ***argvT);
int ConfigOptions(const char *configFile);
int MemoryForVectorOptions();
int UnMemVectorOptions();
int ReadVectorOptions(int argc, const char *argv[]);
#endif



