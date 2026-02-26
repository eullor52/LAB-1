#ifndef LINEFORM_H
#define LINEFORM_H
#include "complex.h"
#include <stdlib.h>

typedef struct
{
    void* left;
    void* right;
    size_t size_left;
    size_t size_right;
    void* (*dif_lnf)(void* right, void* left, size_t size_right, size_t size_left);
    void* (*add_lnf)(void* right, void* left, size_t size_right, size_t size_left);
}Lnform1;

typedef struct 
{
    void* lnf;
    void* arg;
    size_t size_lnf;
    void* (*mul_lnf)(void* lnf, void* coef, size_t size_lnf);
    void* (*calc_lnf)(void* lnf, void* vrlbs, size_t size_lnf);
}Lnform2;



#endif