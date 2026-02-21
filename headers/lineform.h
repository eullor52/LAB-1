#ifndef LINEFORM_H
#define LINEFORM_H

typedef struct
{
    void* coefs;
    Func operations;
}Lnform;

typedef struct
{
    Lnform (*add_lnf)(void* right, void* left);
    Lnform (*dif_lnf)(void* right, void* left);
    Lnform (*mul_lnf)(void* lnf, void* coef);
    void* (*calk_lnf)(void* lnf, void* vrlbs);
}Func;




#endif