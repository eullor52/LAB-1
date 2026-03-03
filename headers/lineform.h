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
    void* coefs;
    void* vrbls;
    size_t size_lnf;
    void* (*mul_lnf)(void* lnf, void* coef, size_t size_lnf);
    void* (*calc_lnf)(void* lnf, void* vrlbs, size_t size_lnf);
}Lnform2;

Lnform1* set_lnf1(void* lnf1, unsigned int size1, const char type1, void* lnf2, unsigned int size2, const char type2);

Lnform2* set_lnf2(void* coefs, unsigned int coef_size, const char coef_type, void* vrbls, const char vrbl_type);

#endif