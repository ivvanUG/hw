#ifndef ONRun_H
#define ONRun_H
#include <stdlib.h>

#include "ioptions.h"


int On_InitRutine(int set);
int Get_Generation(int set, int _gen);
int External_Evaluator(int set, int value);
int On_FinalizeRutine(int set);
int On_Generation(int set);
int On_InitRun(int argc, char *argv[],const char *optionsFile);
int On_FinalizeRun();

#endif
