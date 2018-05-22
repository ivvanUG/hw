#include "imemo.h"


double **dmatrix(int _n, int _m)
{
  int i;
  double **_mat=(double **)malloc(_n*sizeof(double*));
  _mat[0]= (double *)malloc(_n*_m*(sizeof(double)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

double *dvector(int _n)
{
  double *_vec=(double *)malloc(_n*sizeof(double));
return _vec;
}

float **fmatrix(int _n, int _m)
{
  int i;
  float **_mat=(float **)malloc(_n*sizeof(float*));
  _mat[0]= (float *)malloc(_n*_m*(sizeof(float)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

float *fvector(int _n)
{
  float *_vec=(float *)malloc(_n*sizeof(float));
return _vec;
}


int **imatrix(int _n, int _m)
{
  int i;
  int **_mat=(int **)malloc(_n*sizeof(int*));
  _mat[0]=(int *)malloc(_n*_m*(sizeof(int)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

int *ivector(int _n)
{
  int *_vec=(int *)malloc(_n*sizeof(int));
return _vec;
}

unsigned int **uimatrix(int _n, int _m)
{
  int i;
  unsigned int **_mat=(unsigned int **)malloc(_n*sizeof(unsigned int*));
  _mat[0]=(unsigned int *)malloc(_n*_m*(sizeof(unsigned int)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

unsigned int *uivector(int _n)
{
  unsigned int *_vec=(unsigned int *)malloc(_n*sizeof(unsigned int));
return _vec;
}

long int **limatrix(int _n, int _m)
{
  int i;
  long int **_mat=(long int **)malloc(_n*sizeof(long int*));
  _mat[0]=(long int *)malloc(_n*_m*(sizeof(long int)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

long int *livector(int _n)
{
  long int *_vec=(long int *)malloc(_n*sizeof(long int));
return _vec;
}


unsigned long int **ulimatrix(int _n, int _m)
{
  int i;
  unsigned long int **_mat=(unsigned long int **)malloc(_n*sizeof(unsigned long int*));
  _mat[0]=(unsigned long int *)malloc(_n*_m*(sizeof(unsigned long int)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}


unsigned long int *ulivector(int _n)
{
  unsigned long int *_vec=(unsigned long int *)malloc(_n*sizeof(unsigned long int));
return _vec;
}


char **cmatrix(int _n, int _m)
{
  int i;
  char **_mat=(char **)malloc(_n*sizeof(char*));
  _mat[0]=(char *)malloc(_n*_m*(sizeof(char)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

char *cvector(int _n)
{
  char *_vec=(char *)malloc(_n*sizeof(char));
return _vec;
}

unsigned char **ucmatrix(int _n, int _m)
{
  int i;
  unsigned char **_mat=(unsigned char **)malloc(_n*sizeof(unsigned char*));
  _mat[0]=(unsigned char *)malloc(_n*_m*(sizeof(unsigned char)));
  for (i=1; i<_n; i++)
       _mat[i]= &_mat[0][i*_m];
return _mat;
}

unsigned char *ucvector(int _n)
{
  unsigned char *_vec=(unsigned char *)malloc(_n*sizeof(unsigned char));
return _vec;
}

double **iclone_dmatrix(int _n, int _m, double **_mat)
{
  int i,j;
  double **mat=(double **)malloc(_n*sizeof(double*));
  mat[0]= (double *)malloc(_n*_m*(sizeof(double)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];
return mat;
}

double *iclone_dvector(int _n, double *_vec)
{
  double *vec=(double *)malloc(_n*sizeof(double));
  int i;
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}

float **iclone_fmatrix(int _n, int _m, float **_mat)
{
  int i,j;
  float **mat=(float **)malloc(_n*sizeof(float*));
  mat[0]= (float *)malloc(_n*_m*(sizeof(float)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];

return mat;
}

float *iclone_fvector(int _n, float *_vec)
{
  int i;
  float *vec=(float *)malloc(_n*sizeof(float));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}


int **iclone_imatrix(int _n, int _m, int **_mat)
{
  int i,j;
  int **mat=(int **)malloc(_n*sizeof(int*));
  mat[0]=(int *)malloc(_n*_m*(sizeof(int)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];

return mat;
}

int *iclone_ivector(int _n, int *_vec)
{
    int i;
  int *vec=(int *)malloc(_n*sizeof(int));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}

long int **iclone_limatrix(int _n, int _m, long int **_mat)
{
  int i,j;
  long int **mat=(long int **)malloc(_n*sizeof(long int*));
  mat[0]=(long int *)malloc(_n*_m*(sizeof(long int)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];

return mat;
}

long int *iclone_livector(int _n,long int *_vec)
{
    int i;
  long int *vec=(long int *)malloc(_n*sizeof(long int));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}



unsigned long int **iclone_ulimatrix(int _n, int _m,unsigned long int **_mat)
{
  int i,j;
  unsigned long int **mat=(unsigned long int **)malloc(_n*sizeof(unsigned long int*));
  mat[0]=(unsigned long int *)malloc(_n*_m*(sizeof(unsigned long int)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];
 
return mat;
}


unsigned long int *iclone_ulivector(int _n, unsigned long int *_vec)
{
  int i;
  unsigned long int *vec=(unsigned long int *)malloc(_n*sizeof(unsigned long int));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}


char **iclone_cmatrix(int _n, int _m, char **_mat)
{
  int i,j;
  char **mat=(char **)malloc(_n*sizeof(char*));
  mat[0]=(char *)malloc(_n*_m*(sizeof(char)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];

return mat;
}

char *iclone_cvector(int _n, char *_vec)
{
  int i;
  char *vec=(char *)malloc(_n*sizeof(char));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;

}

unsigned char **iclone_ucmatrix(int _n, int _m, unsigned char **_mat)
{
  int i,j;
  unsigned char **mat=(unsigned char **)malloc(_n*sizeof(unsigned char*));
  mat[0]=(unsigned char *)malloc(_n*_m*(sizeof(unsigned char)));
  for (i=1; i<_n; i++)
       mat[i]= &mat[0][i*_m];
  for (i=0; i<_n; i++)
    for (j=0; j<_m; j++)
        mat[i][j]=_mat[i][j];
return mat;
}

unsigned char *iclone_ucvector(int _n, unsigned char *_vec)
{
  int i;
  unsigned char *vec=(unsigned char *)malloc(_n*sizeof(unsigned char));
  for (i=0; i<_n; i++)
        vec[i]=_vec[i]; 
return vec;
}


int free_dmatrix(double **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_fmatrix(float **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_imatrix(int **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_uimatrix(unsigned  int **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_limatrix(long int **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_ulimatrix(unsigned long int **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}


int free_cmatrix(char **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

int free_ucmatrix(unsigned char **_mat, int _n)
{
        if (_mat)
        {
                free(_mat[0]);
                free(_mat);  
        }
return 0;       
}

 
