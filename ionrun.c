#include "ionrun.h"

///It is different to 0 when the program starts and 0 otherwise
int On_InitRun(int argc, char *argv[],const char *optionsFile)
{
   int argc0,i,flag=0;
   char **argv0;
///Reads the configuration file with the options for this program in: ./config/sabin.options
  ConfigOptions(optionsFile);

///Reads the user settings from the command line
  if (!read_options(argc, (const char**)argv) ){
///If no options are read from the command line, then it intends to read an input file
      flag=OptInputFile(argc, argv, &argc0, &argv0);
      read_options(argc0, (const char**)argv0);
  }
  MemoryForVectorOptions();
  if (flag)
     ReadVectorOptions(argc0, (const char**)argv0);
  else
     ReadVectorOptions(argc, (const char**)argv);
  if (flag){
      for (i=0; i<argc0; i++)
          free(argv0[i]);
      free(argv0);
  }
 return 0;
}


///It is different to 0 when the program Finalizes and 0 otherwise
int On_FinalizeRun()
{
   UnMemVectorOptions();

 return 0;
}






///It is different to 0 when the program starts and 0 otherwise
int On_InitRutine(int set)
{
  static int flag;
  static int tmpflag;
  if (set){
     flag=1;
     tmpflag=0;
  }

  if (tmpflag>=2)
  {
     flag=0;
  }
    tmpflag+=flag;
 return flag;
}


///It is different to 0 when the program Finalizes and 0 otherwise
int On_FinalizeRutine(int set)
{
  static int flag;
  static int tmpflag;
  if (set){
     flag=1;
     tmpflag=0;
  }

  if (tmpflag>=2)
  {
     flag=0;
  }
    tmpflag+=flag;
 return flag;
}



///It is different to 0 when each generation/iteration starts and 0 otherwise
int On_Generation(int set)
{
  static int flag;
  static int tmpflag;
  if (set){
     flag=1;
     tmpflag=0;
  }

  if (tmpflag>=2)
  {
     flag=0;
  }
    tmpflag+=flag;
 return flag;
}



///Returns the generation index
int Get_Generation(int set, int _gen)
{
  static int gen;
  if (set)
     gen=_gen;
 return gen;
}



///Returns the 0 if it is used a coded function and different to 0 if an external evaluator is used
int External_Evaluator(int set, int value)
{
    static int useit;
    if (set) useit=value;
return useit;
}






