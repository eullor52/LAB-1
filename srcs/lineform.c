#include "lineform.h"

Lnform create_cmplx_lnf(Complex* p, size_t size)
{
    Lnform lnf;
    
    lnf.coefs = p;
    lnf.size = size;
}