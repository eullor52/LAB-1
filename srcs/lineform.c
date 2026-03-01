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

int set_lnf1(Lnform1* lnf, void* lnf1, unsigned int size1, const char type1, void* lnf2, unsigned int size2, const char type2)
{
    if (lnf == NULL || lnf1 == NULL || lnf2 == NULL || (type1!='c' && type1!='d') || (type2!='c' && type2!='d')) return 1;

    if (type1 == 'c') lnf->left = (Complex*)lnf1;
    else lnf->left = (double*)lnf1;

    lnf->size_left = size1;

    if (type2 == 'c') lnf->right = (Complex*)lnf2;
    else lnf->right = (double*)lnf2;

    lnf->size_right = size2;

    if (type1 == 'c' || type2 == 'c') lnf->result_type = 'c';
    else lnf->result_type = 'd';

    set_lnf1_func(lnf, type1, type2);
    
    return 0;
}

Lnform2* init_lnf2()
{
    Lnform2 lnf = {NULL, NULL, 0, NULL, NULL};
    return &lnf;
}

int set_lnf2(Lnform2* lnf, void* coefs, unsigned int coef_size, const char coef_type, void* vrbls, const char vrbl_type)
{
    if (lnf == NULL || coefs == NULL || vrbls == NULL || (coef_type!='c' && coef_type!='d') || (vrbl_type!='c' && vrbl_type!='d')) return 1;

    if (coef_type == 'c') lnf->coefs = (Complex*)coefs;
    else lnf->coefs = (double*)coefs;

    lnf->size_lnf = coef_size;

    if (vrbl_type == 'c') lnf->vrbls == (Complex*)vrbls;
    else lnf->vrbls = (double*)vrbls;

    set_lnf2_func(lnf, coef_type, vrbl_type);

    return 0;
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
            lnf->mul_lnf = lnf_dbl_mul_dbl;
            lnf->calc_lnf = lnf_dbl_calc_dbl;
        }
    }
}
