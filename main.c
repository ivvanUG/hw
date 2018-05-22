#include "ioptions.h"
#include "ionrun.h"
#include <omp.h>

int main(int argc, char *argv[])
{
   int print,nthreads;


//Sets the options for this application using the file in config/gibbs.options. Additional options can be set
On_InitRun(argc, argv,"config/hw.options");
   iOptionStruct option;
   option=Get_Option_By_Name("-print");
   print=option.ivalue;
   option=Get_Option_By_Name("-nthreads");
   nthreads=option.ivalue;
   omp_set_num_threads(nthreads);
   if (print==2)
   {
        #pragma omp parallel
        {
          if (omp_get_thread_num()==0)
            printf("Master thread says: I am usin %d threads\n",omp_get_num_threads());
          printf("Thread %d says: Hello world!\n",omp_get_thread_num());
        }
   }else if(print==1)
   {
      printf("The print option is set to 0, thus the process is silent\n");
   }


On_FinalizeRun();
 return 0;
}
