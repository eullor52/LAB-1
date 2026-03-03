#include "lineform.h"
#include "operations.h"

static void set_lnf1_func(Lnform1* lnf, const char type1, const char type2)
{
    if (type1 == 'c')
    {
        if (type2 == 'c') 
        {
            lnf->add_lnf = lnf_cmplx_add_cmplx;
            lnf->dif_lnf = lnf_cmplx_dif_cmplx;
        }
        else
        {
            lnf->add_lnf = lnf_cmplx_add_dbl;
            lnf->dif_lnf = lnf_cmplx_dif_dbl;
        }
    }
    else
    {
        if (type2 == 'c') 
        {
            lnf->add_lnf = lnf_dbl_add_cmplx;
            lnf->dif_lnf = lnf_dbl_dif_cmplx;
        }
        else 
        {
            lnf->add_lnf = lnf_dbl_add_dbl;
            lnf->dif_lnf = lnf_dbl_dif_dbl;
        }
    }
}

Lnform1* set_lnf1(void* lnf1, unsigned int size1, const char type1, void* lnf2, unsigned int size2, const char type2)
{
    Lnform1* lnf = malloc(sizeof(Lnform1));
    
    lnf->left = lnf1;
    lnf->size_left = size1;

    lnf->right = lnf2;
    lnf->size_right = size2;

    set_lnf1_func(lnf, type1, type2);

    return lnf;
}

static void set_lnf2_func(Lnform2* lnf, const char type1, const char type2)
{
    if (type1 == 'c')
    {
        if (type2 == 'c')
        {
            lnf->mul_lnf = lnf_cmplx_mul_cmplx;
            lnf->calc_lnf = lnf_cmplx_calc_cmplx;
        }
        else
        {
            lnf->mul_lnf = lnf_cmplx_mul_dbl;
            lnf->calc_lnf = lnf_cmplx_calc_dbl;
        }
    }
    else
    {
        if (type2 == 'c')
        {
            lnf->mul_lnf = lnf_dbl_mul_cmplx;
            lnf->calc_lnf = lnf_dbl_calc_cmplx;
        }
        else
        {
            lnf->mul_lnf =  lnf_dbl_mul_dbl;
            lnf->calc_lnf =  lnf_dbl_calc_dbl;
        }
    }
}

Lnform2* set_lnf2(void* coefs, unsigned int coef_size, const char coef_type, void* vrbls, const char vrbl_type)
{
    Lnform2* lnf = (Lnform2*)malloc(sizeof(Lnform2));

    lnf->coefs = coefs;
    lnf->size_lnf = coef_size;

    lnf->vrbls = vrbls;

    set_lnf2_func(lnf, coef_type, vrbl_type);

    return lnf;
}

