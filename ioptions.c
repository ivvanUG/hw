#include "ioptions.h"
int iOptionCounter(int _counter)
{
  static int counter;
  if (_counter>=0)
      counter=_counter;
  return counter;
}

iOptionStruct Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index)
{
  static iOptionStruct options[MAXOPTIONS];
  if (index<0 || index>MAXOPTIONS)
     return options[0];

  if (_set){
          strcpy(options[index].option,_option);
          strcpy(options[index].svalue,_defaultStringValue);
          if (_shortdescription)
            strcpy(options[index].shortdescription,_shortdescription);
          options[index].dvalue=_defaultDoubleValue;
          options[index].ivalue=_defaultIntegerValue;
          options[index].set=_IfSetbyDefault;
          options[index].order=index;
          options[index].ivector=NULL;///If the option is of type 'integer vector' this is used
          options[index].dvector=NULL;///If the option is of type 'integer vector' this is used
          options[index].vsize=0; ///If the option reads a vector, this is the vector size
  }
return   options[index];
}

iOptionStruct* Set_Get_Option2(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index)
{
  static iOptionStruct options[MAXOPTIONS];

  if (index<0 || index>MAXOPTIONS)
     return &options[0];

  if (_set){
          strcpy(options[index].option,_option);
          strcpy(options[index].svalue,_defaultStringValue);
          options[index].opttype=_opttype;
          if (_shortdescription)
              strcpy(options[index].shortdescription,_shortdescription);
          options[index].dvalue=_defaultDoubleValue;
          options[index].ivalue=_defaultIntegerValue;
          options[index].set=_IfSetbyDefault;
          options[index].order=index;
          options[index].ivector=NULL;///If the option is of type 'integer vector' this is used
          options[index].dvector=NULL;///If the option is of type 'integer vector' this is used
          options[index].vsize=0; ///If the option reads a vector, this is the vector size
  }

return   &options[index];
}



iOptionStruct *Get_Option_By_Index(int index)
{
  iOptionStruct* option= Set_Get_Option2("",'\0',0.0,0,"","",false,false,index);
 return option;
}

int idefine_new_option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_description, bool _IfSetbyDefault, bool _FirstOption)
{

  static int Counter;

  if (_FirstOption)
     Counter=0;
  if (Counter>MAXOPTIONS || Counter <0)
    Counter=0;

  Set_Get_Option(_option,_opttype,_defaultDoubleValue, _defaultIntegerValue, _defaultStringValue,_description, _IfSetbyDefault,true, Counter);
  Counter++;
  iOptionCounter(Counter);
return Counter;
}

int print_options()
{
  int i;
  iOptionStruct* option;

  for (i=0; i<iOptionCounter(-1); i++)
  {
    option=Get_Option_By_Index(i);

    if (option->set){
       if (option->opttype=='s')
           printf("%s\t %s\n",option->option, option->svalue);
       else if (option->opttype=='d')
           printf("%s\t %g\n",option->option, option->dvalue);
       else if (option->opttype=='i')
           printf("%s\t %d\n",option->option, option->ivalue);
       else if (option->opttype=='n')
           printf("%s\n",option->option);
       else if (option->opttype=='j')
           printf("%s\n",option->option);
       else if (option->opttype=='f')
           printf("%s\n",option->option);
    else
        printf("%s has not a valid type.\n",option->option);
    }
  }
return 0;
}

iOptionStruct Get_Option_By_Name(const char* _option)
{
   int i;
   iOptionStruct* option=NULL;
   iOptionStruct AuxOpt;
   for (i=0; i<iOptionCounter(-1); i++)
   {
        option=Get_Option_By_Index(i);
        if (strcmp(option->option,_option)==0)
           break;
   }
   if (option==NULL)
   {
          strcpy(AuxOpt.option,"");
          strcpy(AuxOpt.svalue,"");
          AuxOpt.opttype='n';
          strcpy(AuxOpt.shortdescription,"");
          AuxOpt.dvalue=0.0;
          AuxOpt.ivalue=0;
          AuxOpt.set=false;
          AuxOpt.order=-1;
          AuxOpt.ivector=NULL;///If the option is of type 'integer vector' this is used
          AuxOpt.dvector=NULL;///If the option is of type 'integer vector' this is used
          AuxOpt.vsize=0; ///If the option reads a vector, this is the vector size
   }
   else
       AuxOpt=*option;

return AuxOpt;
}



///Return EXIT_FAILURE if there are unknown options in the arguments
///Also return EXIT_FAILURE if there are not arguments for the option, I need to condider options with no arguments
int read_options(int argc, const char *argv[])
{
  int i,j,flag;
  int nopt=iOptionCounter(-1);
  iOptionStruct* option;
  for (j=1; j<argc; j++){
      for (i=0; i< nopt; i++){
           flag=0;
           option=Get_Option_By_Index(i);
           if (strcmp(argv[j],option->option)==0)
           {
               if (option->opttype=='s'){
                   j++;
                   strcpy(option->svalue,argv[j]);
                   option->set=true;
                   option->order=j-1;
                   flag=1;
                   if (strcmp(option->option,"-logfile")==0)
                   {
                        set_and_get_logfile(option->svalue, true);
                   }
                   break;
               }
               if (option->opttype=='i'){
                   j++;
                   option->ivalue=atoi(argv[j]);
                   option->set=true;
                   option->order=j-1;
                   flag=1;
                   break;
               }
               if (option->opttype=='d'){
                   j++;
                   option->dvalue=atof(argv[j]);
                   option->set=true;
                   option->order=j-1;
                   flag=1;
                   break;
               }
               if (option->opttype=='j'){
                   option->ivalue=atoi(argv[j]);
                   option->set=true;
                   option->order=j-1;
                   flag=1;
                   break;
               }
               if (option->opttype=='f'){
                   option->dvalue=atof(argv[j]);
                   option->set=true;
                   option->order=j-1;
                   flag=1;
                   break;
               }
               if (option->opttype=='n'){
                   option->set=true;
                   option->order=j;
                   flag=1;
                   break;
               }
               flag=1;
               break;
           }
      }
      if (flag==0){
            printf( "The option %s is unkown.", argv[j] );
            LogPrintf( "The option %s is unkown.\n", argv[j] );
          return 0;
      }
  }

return 1;
}


int OptInputFile(int argcO, char **argvO, int *argcT, char ***argvT)
{
        int flag=0;
        FILE *input=NULL;
        int l, maxl=2;
        char c;
        int j,i,anotherflag;
        int argc=*argcT;
        char **argv=NULL;


        for(j=1;j<argcO;j++)
              if(strcmp("-inputfile",argvO[j])==0)
                  flag=j;

        if (!flag && argcO==2){
           input=fopen(argvO[1],"r");
           if (input)
              fclose(input);
           else{
                LogPrintf("%s is not recognized as a file, possible neither as a valid option.\n",argvO[1]);
                return 0;
               }
        }



        if(flag || input!=NULL)
        {

             argc=1;
             if (flag+1>argcO){
                printf("You must provide an input file name.");
                LogPrintf("You must provide an input file name.");
                return -2;
             }

             input=fopen(argvO[flag+1],"r");
             if (!input){
                printf("I can not open the input file.");
                LogPrintf("I can not open the input file.");
                return -1;
             }
             while(!feof(input)){
                  c=fgetc(input);
                  ///elimina comentarios, espacios y lineas en blanco
                  while( (c=='#' || c==' ' || c=='\n') && !feof(input)) {
                       while((c=='#') && !feof(input))
                          while((c!='\n') && !feof(input))
                              c=fgetc(input);
                       while((c=='\n' || c==' ') && !feof(input))
                             c=fgetc(input);
                  }
                    //elimina lineas en blanco si las hubiera
                    l=2;
                  int anotherflag=0;
                  while((c!=' ' && c!='\n') && !feof(input)){
                    //printf("%c",c);
                    fflush(stdout);
                    c=fgetc(input);
                    l++;
                    anotherflag=1;
                  }
                  if (maxl<l)maxl=l;

                  argc+=anotherflag;
                  //printf("\nargc=%d\n",argc);

             }
             fclose(input);
             if (argc>1)
             {
                 argv=(char **)malloc(argc*sizeof(char*));
                 for(i=0; i<argc; i++)
                     argv[i]=(char *)malloc(maxl*sizeof(char));

             }

            input=fopen(argvO[flag+1],"r");
             if (!input){
                printf("I can not open the input file.");
                return -1;
             }
             argc=1;
             while(!feof(input)){
                  c=fgetc(input);
                  ///elimina comentarios, espacios y lineas en blanco
                  while( (c=='#' || c==' ' || c=='\n') && !feof(input)) {
                       while((c=='#') && !feof(input))
                          while((c!='\n') && !feof(input))
                              c=fgetc(input);
                       while((c=='\n' || c==' ') && !feof(input))
                             c=fgetc(input);
                  }
                    //elimina lineas en blanco si las hubiera
                    l=0;
                  anotherflag=0;
                  while((c!=' ' && c!='\n') && !feof(input)){
                    argv[argc][l]=c;
                    c=fgetc(input);
                    l++;
                    anotherflag=1;
                  }
                  if (anotherflag)
                     argv[argc][l]='\0';
                  argc+=anotherflag;
             }
             *argvT=argv;
             *argcT=argc;
          return 1;
        }

 return 0;
}




int ConfigOptions(const char *configFile)
{

        FILE *input=NULL;
        int l, maxl=2;
        char c;
        int anotherflag, ArgsNum=7; ///ArgsNUm==Number of arguments per line that must be in the configuration file
        char argv[7][256];
        int ArgPerLine,argc=1;
        iOptionStruct *opt;
//         int argc=*argcT;
        int quote;
        input=fopen(configFile,"r");
        if (input){
             fclose(input);
        }
        else{
            LogPrintf("I can not open the %s file, when intended to read the options of this application.",configFile);
            return -1;
        }
        for (l=0; l<MAXOPTIONS; l++)
             opt=Set_Get_Option2("",'\0', 0.0,0,"","", false,true,0);


        if(input)
        {
             input=fopen(configFile,"r");
             if (!input){
                printf("I can not open the %s file, when intended to read the options of this application.",configFile);
                LogPrintf("I can not open the %s file, when intended to read the options of this application.",configFile);
                return -1;
             }
             ArgPerLine=0;
             while(!feof(input)){

                  c=fgetc(input);
                  ///Remove commments, blank lines and spaces
                  while( (c=='#' || c==' ' || c=='\n') && !feof(input)) {
                       while((c=='#') && !feof(input))
                          while((c!='\n') && !feof(input))
                              c=fgetc(input);
                       while((c=='\n' || c==' ') && !feof(input))
                             c=fgetc(input);
                  }
                  //elimina lineas en blanco si las hubiera
                  l=2;
                  anotherflag=0;
                  while((c!=' ' && c!='\n') && !feof(input)){
                    c=fgetc(input);
                    l++;
                    anotherflag=1;
                  }
                   ArgPerLine+=anotherflag;
                  if (c=='\n' && anotherflag==1){
                     if (ArgPerLine<ArgsNum){
                         printf("The file %s, is not well written around line %d (black and comments are not counted).\n",configFile,argc);
                         LogPrintf("The file %s, is not well written around line %d (black and comments are not counted).",configFile,argc);
                         return 0;
                     }
                     argc++;
                     ArgPerLine=0;
                  }
                  if (maxl<l)maxl=l;
//                   argc+=anotherflag;

             }
             fclose(input);

//              if (argc>1)
//              {
//                  argv=(char **)malloc(argc*sizeof(char*));
//                  for(i=0; i<argc; i++)
//                      argv[i]=(char *)malloc(maxl*sizeof(char));
//
//              }
             if (argc>1){
             input=fopen(configFile,"r");
             argc=0;
             ArgPerLine=0;
             while(!feof(input)){
                c=fgetc(input);
                  ///elimina comentarios, espacios y lineas en blanco
                  while( (c=='#' || c==' ' || c=='\n') && !feof(input)) {
                       while((c=='#') && !feof(input))
                          while((c!='\n') && !feof(input))
                              c=fgetc(input);
                       while((c=='\n' || c==' ') && !feof(input))
                             c=fgetc(input);
                  }

                if(ArgPerLine!=5 && ArgPerLine!=6){
                  l=0;
                  anotherflag=0;
                  while((c!=' ' && c!='\n') && !feof(input)){
                    argv[ArgPerLine][l]=c;
                    c=fgetc(input);
                    l++;
                    anotherflag=1;
                  }
                  if (anotherflag){
                     argv[ArgPerLine][l]='\0';

                  }
                  ArgPerLine+=anotherflag;
                }else{
                    ///fscanf(input,"\"%s\"",argv[ArgPerLine]);
                    quote=0;
                    l=0;
                    if (c=='\"')
                        quote=1;
                    c=fgetc(input);
                    while(c!='\n' && !feof(input)){
                        if (c=='\"')
                            quote=1-quote;
                        if (c=='\"' && quote==0)
                            break;

                        else{
                            argv[ArgPerLine][l]=c;
                            l++;
                        }
                        c=fgetc(input);
                        anotherflag=1;
                     }

                     argv[ArgPerLine][l]='\0';
                     ArgPerLine++;
                }


                  if (ArgPerLine==ArgsNum){
                     argc++;
                     ArgPerLine=0;

                     if (argv[1][0]=='i'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                       opt=Set_Get_Option2(argv[0],argv[1][0], 0.0, atoi(argv[3]),"",argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                     }
                     if (argv[1][0]=='d'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                       opt=Set_Get_Option2(argv[0],argv[1][0], atof(argv[3]),0,"",argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                     }
                     if (argv[1][0]=='s'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                       opt=Set_Get_Option2(argv[0],argv[1][0], 0.0,0,argv[3],argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                     }
                     if (argv[1][0]=='n'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                       opt=Set_Get_Option2(argv[0],argv[1][0], 0.0,0,argv[3],argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                     }
                     if (argv[1][0]=='j'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                       opt=Set_Get_Option2(argv[0],argv[1][0], 0.0, atoi(argv[3]),"",argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                       strcpy((*opt).vsizeOpt,argv[5]);
                       (*opt).vsize=atoi(argv[2]);
                     }
                     if (argv[1][0]=='f'){
//                        Set_Get_Option(const char *_option,char _opttype, double _defaultDoubleValue, int _defaultIntegerValue, const char *_defaultStringValue,const char *_shortdescription, bool _IfSetbyDefault,bool _set, int index);
                        opt=Set_Get_Option2(argv[0],argv[1][0], atof(argv[3]), 0,"",argv[6], (bool)atoi(argv[2]),true,atoi(argv[4]) );
                        strcpy((*opt).vsizeOpt,argv[5]);
                        (*opt).vsize=atoi(argv[2]);
                     }
                     iOptionCounter(argc);
                  }

             }
          fclose(input);
          return 1;
          }
        }

 return 0;
}

int MemoryForVectorOptions()
{
  int i,j;
  int nopt=iOptionCounter(-1);
  iOptionStruct *option,optSize;

  for (i=0; i< nopt; i++){
      option=Get_Option_By_Index(i);
      if (option->opttype=='j' || option->opttype=='f'){
         if (option->vsizeOpt!='\0'){
             optSize=Get_Option_By_Name(option->vsizeOpt);
             option->vsize=optSize.ivalue;
         }
             if (option->opttype=='j'){
                 option->ivector=(int*)malloc(option->vsize*sizeof(int));
             }
             if (option->opttype=='f'){
                 option->dvector=(double*)malloc(option->vsize*sizeof(double));
             }
         if (option->vsizeOpt!='\0'){
             for (j=0; j<option->vsize; j++){
                if (option->opttype=='j'){
                    option->ivector[j]=option->ivalue;
                }
                if (option->opttype=='f'){
                    option->dvector[j]=option->dvalue;
                }
             }
         }
         else{
             for (j=0; j<option->vsize; j++){
                if (option->opttype=='j'){
                    option->ivector[j]=0;
                }
                if (option->opttype=='f'){
                    option->dvector[j]=0.0;
                }
             }
         }

      }
  }

return 0;
}

int UnMemVectorOptions()
{
  int i;
  int nopt=iOptionCounter(-1);
  iOptionStruct *option;
  for (i=0; i< nopt; i++){
      option=Get_Option_By_Index(i);
      if (option->opttype=='j' || option->opttype=='f'){
         if (option->vsizeOpt!='\0'){
             if (option->opttype=='j')
                 free(option->ivector);
             if (option->opttype=='f')
                 free(option->dvector);
         }
      }
  }
return 0;
}


int ReadVectorOptions(int argc, const char *argv[])
{
  int i,j,flag,k;
  int nopt=iOptionCounter(-1);
  iOptionStruct* option;
  for (j=1; j<argc; j++){
      for (i=0; i< nopt; i++){
           flag=0;
           option=Get_Option_By_Index(i);
           if (strcmp(argv[j],option->option)==0)
           {
               if (option->opttype=='j'){
                   option->set=true;
                    for (k=0; k<option->vsize; k++)
                        scanf("%d", &option->ivector[k]);
                   option->order=j;
                   flag=1;
                   break;
               }
               if (option->opttype=='f'){
                   option->set=true;
                    for (k=0; k<option->vsize; k++)
                        scanf("%lf", &option->dvector[k]);
                   option->order=j;
                   flag=1;
                   break;
               }
               if (option->opttype=='i' || option->opttype=='d' || option->opttype=='s'){
                  j++;
                  flag=1;
                  break;
               }
               if (option->opttype=='n'){
                  flag=1;
                  break;
               }
           }
      }
      if (flag==0){
            printf( "The option %s is unkown.", argv[j]);
            LogPrintf( "The option %s is unkown.\n", argv[j]);
          return 0;
      }
  }

    return 0;
}

