#ifndef IMEMO_H
#define IMEMO_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double **dmatrix(int _n, int _m);
double *dvector(int _n);
int **imatrix(int _n, int _m);
int *ivector(int _n);
unsigned int **uimatrix(int _n, int _m);
unsigned int *uivector(int _n);
float **fmatrix(int _n, int _m);
float *fvector(int _n);
long int **limatrix(int _n, int _m);
long int *livector(int _n);
unsigned long int **ulimatrix(int _n, int _m);
unsigned long int *ulivector(int _n);
char **cmatrix(int _n, int _m);
char *cvector(int _n);
unsigned char **ucmatrix(int _n, int _m);
unsigned char *ucvector(int _n);

double **iclone_dmatrix(int _n, int _m, double **_mat);
double *iclone_dvector(int _n, double *_vec);
int **iclone_imatrix(int _n, int _m, int **_mat);
int *iclone_ivector(int _n, int *_vec);
unsigned int **iclone_uimatrix(int _n, int _m,unsigned int **_mat);
unsigned int *iclone_uivector(int _n, unsigned int *_vec);
float **iclone_fmatrix(int _n, int _m, float **_mat);
float *iclone_fvector(int _n, float *_vec);
long int **iclone_limatrix(int _n, int _m, long int **_mat);
long int *iclone_livector(int _n,long int *_vec);
unsigned long int **iclone_ulimatrix(int _n, int _m,unsigned long int **_mat);
unsigned long int *iclone_ulivector(int _n, unsigned long int *_vec);
char **iclone_cmatrix(int _n, int _m, char **_mat);
char *iclone_cvector(int _n, char *_vec);
unsigned char **iclone_ucmatrix(int _n, int _m, unsigned char **_mat);
unsigned char *iclone_ucvector(int _n, unsigned char *_vec);



int free_dmatrix(double **_mat, int _n);
int free_fmatrix(float **_mat, int _n);
int free_imatrix(int **_mat, int _n);
int free_limatrix(long int **_mat, int _n);
int free_ulimatrix(unsigned long int **_mat, int _n);
int free_cmatrix(char **_mat, int _n);
int free_ucmatrix(unsigned char **_mat, int _n);


#endif 
