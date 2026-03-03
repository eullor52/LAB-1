#include "operations.h"

static double max(double a, double b)
{
    if (a < b) return b;
    else return a;
}

/*=======================Сложение=======================*/

void* lnf_cmplx_add_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    Complex* left = (Complex*)v_left;
    Complex* right = (Complex*)v_right;
    Complex* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = sum_cmplx((right + i), (left + i));
    else for (int i = 0; i < size_right; i++) result[i] = sum_cmplx((right + i), (left + i));

    return (void*)result;
}

void* lnf_cmplx_add_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    Complex* left = (Complex*)v_left;
    double* right = (double*)v_right;
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

    return (void*)result;
}

void* lnf_dbl_add_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    double* left = (double*)v_left;
    Complex* right = (Complex*)v_right;
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

    return (void*)result;
}

void* lnf_dbl_add_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    double* left = (double*)v_left;
    double* right = (double*)v_right;
    double* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = right[i] + left[i];
    else for (int i = 0; i < size_right; i++) result[i] = right[i] + left[i];

    return (void*)result;
}

/*=======================Вычитание=======================*/ 

void* lnf_cmplx_dif_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    Complex* left = (Complex*)v_left;
    Complex* right = (Complex*)v_right;
    Complex* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) for (int i = 0; i < size_left; i++) result[i] = dif_cmplx((right + i), (left + i));
    else for (int i = 0; i < size_right; i++) result[i] = dif_cmplx((right + i), (left + i));

    return (void*)result;
}

void* lnf_cmplx_dif_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    Complex* left = (Complex*)v_left;
    double* right = (double*)v_right;
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
        for (int i = size_left; i < size_right; i++) result[i].Re = (-1) * right[i];
    }

    return (void*)result;
}

void* lnf_dbl_dif_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    double* left = (double*)v_left;
    Complex* right = (Complex*)v_right;
    Complex* result;
    
    if (max(size_left,size_right) == size_right)
    {
        result = right;
        for (int i = 0; i < size_right; i++) 
        {
            result[i].Re = left[i] - right[i].Re;
            result[i].Im = (-1) * right[i].Im;
        }
    }

    else
    { 
        result = (Complex*)malloc(sizeof(Complex)*size_left);
        for (int i = 0; i < size_right; i++) 
        {
            result[i].Re = left[i] - right[i].Re;
            result[i].Im = (-1) * right[i].Im;
        }
        for (int i = size_right; i < size_left; i++) result[i].Re = left[i];
    }

    return (void*)result;
}

void* lnf_dbl_dif_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right)
{
    double* left = (double*)v_left;
    double* right = (double*)v_right;

    double* result = (size_left < size_right) ? right : left;

    if (size_left < size_right) 
    {
        for (int i = 0; i < size_left; i++) result[i] = left[i] - right[i];
        for (int i = size_left; i < size_right; i++) result[i] = (-1) * right[i];
    }

    else for (int i = 0; i < size_right; i++) result[i] = right[i] - left[i];

    return (void*)result;
}

/*=======================Умножение=======================*/

void* lnf_cmplx_mul_cmplx(void* v_lnf, void* v_coef, size_t size_lnf)
{
    Complex* lnf = (Complex*)v_lnf;
    Complex* coef = (Complex*)v_coef;

    for (int i = 0; i < size_lnf; i++) lnf[i] = mult_cmplx((lnf + i), coef);
    return (void*)lnf;
}

void* lnf_cmplx_mul_dbl(void* v_lnf, void* v_coef, size_t size_lnf)
{
    Complex* lnf = (Complex*)v_lnf;
    double* coef = (double*)v_coef;
    Complex cmplx_coef = {*coef, 0};

    for (int i = 0; i < size_lnf; i++) lnf[i] = mult_cmplx((lnf + i), &cmplx_coef);

    return (void*)lnf;
}

void* lnf_dbl_mul_cmplx(void* v_lnf, void* v_coef, size_t size_lnf)
{
    double* lnf = (double*)v_lnf;
    Complex* coef = (Complex*)v_coef;

    Complex* result = (Complex*)(sizeof(Complex)*size_lnf); 
    Complex temp;   

    if (result == NULL) return result;
    for (int i = 0; i < size_lnf; i++)
    {
        temp.Re = lnf[i];
        temp.Im = 0;

        result[i] = mult_cmplx(&temp, coef);
    }

    return (void*)result;
}

void* lnf_dbl_mul_dbl(void* v_lnf, void* v_coef, size_t size_lnf)
{
    double* lnf = (double*)v_lnf;
    double* coef = (double*)v_coef;

    double* result = malloc(sizeof(double)*size_lnf);

    for (int i = 0; i < size_lnf; i++) result[i] = lnf[i]*(*coef);

    return (void*)result;
}

/*=======================Вычисление=======================*/

void* lnf_cmplx_calc_cmplx(void* v_lnf, void* v_vrlbs, size_t size_lnf)
{
    Complex* lnf = (Complex*)v_lnf;
    Complex* vrlbs = (Complex*)v_vrlbs;

    Complex* result = malloc(sizeof(Complex));
    *result = *lnf; 
    Complex temp;

    for (int i = 1; i < size_lnf; i++)
    {
        temp = mult_cmplx((lnf + i),(vrlbs + i - 1));
        *result = sum_cmplx( &temp, result);
    }

    return (void*)result;
}

void* lnf_cmplx_calc_dbl(void* v_lnf, void* v_vrlbs, size_t size_lnf)
{
    Complex* lnf = (Complex*)v_lnf;
    double* vrlbs = (double*)v_vrlbs;

    Complex* result = malloc(sizeof(Complex));
    *result = *lnf;
    Complex temp, cmplx_vrlb;

    for (int i = 1; i < size_lnf; i++)
    {
        cmplx_vrlb.Re = vrlbs[i-1];
        cmplx_vrlb.Im = 0;

        temp = mult_cmplx((lnf + i), &cmplx_vrlb);
        *result = sum_cmplx( &temp, result);
    }

    return (void*)result;
}

void* lnf_dbl_calc_cmplx(void* v_lnf, void* v_vrlbs, size_t size_lnf)
{
    double* lnf = (double*)v_lnf;
    Complex* vrlbs = (Complex*)v_vrlbs;

    Complex* result = malloc(sizeof(Complex));
    result->Re = *lnf;
    result->Im = 0;
    Complex temp, cmplx_elem;

    for (int i = 1; i < size_lnf; i++)
    {
        cmplx_elem.Re = lnf[i];
        cmplx_elem.Im = 0;

        temp = mult_cmplx((vrlbs + i - 1), &cmplx_elem);
        *result = sum_cmplx( &temp, result);
    }

    return (void*)result;
}

void* lnf_dbl_calc_dbl(void* v_lnf, void* v_vrlbs, size_t size_lnf)
{
    double* lnf = (double*)v_lnf;
    double* vrlbs = (double*)v_vrlbs;

    double* result = malloc(sizeof(double));
    *result = *lnf;

    for (int i = 1; i < size_lnf; i++) *result  += vrlbs[i-1] * lnf[i];

    return (void*)result;
}