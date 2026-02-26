#include "operations.h"

/*=======================Сложение=======================*/

Complex* lnf_cmplx_add_cmplx(Complex* left, Complex* right,  size_t size_left, size_t size_right)
{
    Complex* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = sum_cmplx((right + i), (left + i));
    else for (int i = 0; i < size_right; i++) result[i] = sum_cmplx((right + i), (left + i));

    return result;
}

Complex* lnf_cmplx_add_dbl(Complex* left, double* right, size_t size_left, size_t size_right)
{
    Complex* result;

    if (max(size_left,size_right) == size_left)
    {
        result = left;
        for (int i = 0; i < size_right; i++) result[i].Re = left[i].Re + right[i];
    }

    else
    { 
        result = malloc(sizeof(Complex)*size_right);
        for (int i = 0; i < size_left; i++) result[i].Re = left[i].Re + right[i];
        for (int i = size_left; i < size_right; i++) result[i].Re = right[i];
    }

    return result;
}

Complex* lnf_dbl_add_cmplx(double* left, Complex* right, size_t size_left, size_t size_right)
{
    Complex* result;
    
    if (max(size_left,size_right) == size_right)
    {
        result = right;
        for (int i = 0; i < size_right; i++) result[i].Re = right[i].Re + left[i];
    }

    else
    { 
        result = malloc(sizeof(Complex)*size_left);
        for (int i = 0; i < size_right; i++) result[i].Re = right[i].Re + left[i];
        for (int i = size_right; i < size_left; i++) result[i].Re = left[i];
    }

    return result;
}

/*=======================Вычитание=======================*/ 

Complex* lnf_cmplx_dif_cmplx(Complex* left, Complex* right, size_t size_left, size_t size_right)
{
    Complex* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = dif_cmplx((right + i), (left + i));
    else for (int i = 0; i < size_right; i++) result[i] = dif_cmplx((right + i), (left + i));

    return result;
}

Complex* lnf_cmplx_dif_dbl(Complex* left, double* right, size_t size_left, size_t size_right)
{
    Complex* result;

    if (max(size_left,size_right) == size_left)
    {
        result = left;
        for (int i = 0; i < size_right; i++) result[i].Re = left[i].Re - right[i];
    }

    else
    { 
        result = malloc(sizeof(Complex)*size_right);
        for (int i = 0; i < size_left; i++) result[i].Re = left[i].Re - right[i];
        for (int i = size_left; i < size_right; i++) result[i].Re = right[i];
    }

    return result;
}

Complex* lnf_dbl_dif_cmplx(double* left, Complex* right, size_t size_left, size_t size_right)
{
    Complex* result;
    
    if (max(size_left,size_right) == size_right)
    {
        result = right;
        for (int i = 0; i < size_right; i++) result[i].Re = right[i].Re - left[i];
    }

    else
    { 
        result = malloc(sizeof(Complex)*size_left);
        for (int i = 0; i < size_right; i++) result[i].Re = right[i].Re - left[i];
        for (int i = size_right; i < size_left; i++) result[i].Re = left[i];
    }

    return result;
}

double* lnf_dbl_add_double(double* left, double* right, size_t size_left, size_t size_right)
{
    double* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = right[i] + left[i];
    else for (int i = 0; i < size_right; i++) result[i] = right[i] + left[i];

    return result;
}

double* lnf_dbl_dif_double(double* left, double* right, size_t size_left, size_t size_right)
{
    double* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = right[i] - left[i];
    else for (int i = 0; i < size_right; i++) result[i] = right[i] - left[i];

    return result;
}

/*=======================Умножение=======================*/

Complex* lnf_cplx_mul_cmplx(Complex* lnf, Complex* coef, size_t size_lnf)
{
    for (int i = 0; i < size_lnf; i++) lnf[i] = mult_cmplx((lnf + i), coef);
    return lnf;
}

Complex* lnf_cplx_mul_dbl(Complex* lnf, double* coef, size_t size_lnf)
{
    Complex cmplx_coef = {*coef, 0};

    for (int i = 0; i < size_lnf; i++) lnf[i] = mult_cmplx((lnf + i), &cmplx_coef);

    return lnf;
}

Complex* lnf_dbl_mul_cmplx(double* lnf, Complex* coef, size_t size_lnf)
{
    Complex* result = malloc(sizeof(Complex)*size_lnf); 
    Complex temp;   

    if (result == NULL) return result;
    for (int i = 0; i < size_lnf; i++)
    {
        temp.Re = lnf[i];
        temp.Im = 0;

        result[i] = mult_cmplx(&temp, coef);
    }

    return result;
}

double* lnf_dbl_mul_dbl(double* lnf, double* coef, size_t size_lnf)
{
    double* result = malloc(sizeof(double)*size_lnf);

    for (int i = 0; i < size_lnf; i++) result[i] = lnf[i]*(*coef);

    return result;
}

/*=======================Вычисление=======================*/

Complex lnf_cmplx_calc_cmplx(Complex* lnf, Complex* vrlbs, size_t size_lnf)
{
    Complex result = *lnf;
    Complex temp;

    for (int i = 1; i < size_lnf; i++)
    {
        temp = mult_cmplx((lnf + i),(vrlbs + i - 1));
        result = sum_cmplx( &temp, &result);
    }

    return result;
}

Complex lnf_cmplx_calc_dbl(Complex* lnf, double* vrlbs, size_t size_lnf)
{
    Complex result = *lnf;
    Complex temp, cmplx_vrlb;

    for (int i = 1; i < size_lnf; i++)
    {
        cmplx_vrlb.Re = vrlbs[i-1];
        cmplx_vrlb.Im = 0;

        temp = mult_cmplx((lnf + i), &cmplx_vrlb);
        result = sum_cmplx( &temp, &result);
    }

    return result;
}

Complex lnf_dbl_calc_cmplx(double* lnf, Complex* vrlbs, size_t size_lnf)
{
    Complex result = {*lnf, 0};
    Complex temp, cmplx_elem;

    for (int i = 1; i < size_lnf; i++)
    {
        cmplx_elem.Re = lnf[i];
        cmplx_elem.Im = 0;

        temp = mult_cmplx((vrlbs + i - 1), &cmplx_elem);
        result = sum_cmplx( &temp, &result);
    }

    return result;
}

double lnf_dbl_calc_dbl(double* lnf, double* vrlbs, size_t size_lnf)
{
    double result = *lnf;

    for (int i = 1; i < size_lnf; i++) result  += vrlbs[i-1] * lnf[i];

    return result;
}