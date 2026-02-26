#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "complex.h"
#include <stdlib.h>

Complex* lnf_cmplx_add_cmplx(Complex* left, Complex* right,  size_t size_left, size_t size_right);
Complex* lnf_cmplx_add_dbl(Complex* left, double* right, size_t size_left, size_t size_right);
Complex* lnf_dbl_add_cmplx(double* left, Complex* right, size_t size_left, size_t size_right);
Complex* lnf_cmplx_dif_cmplx(Complex* left, Complex* right, size_t size_left, size_t size_right);
Complex* lnf_cmplx_dif_dbl(Complex* left, double* right, size_t size_left, size_t size_right);
Complex* lnf_dbl_dif_cmplx(double* left, Complex* right, size_t size_left, size_t size_right);
double* lnf_dbl_add_double(double* left, double* right, size_t size_left, size_t size_right);
double* lnf_dbl_dif_double(double* left, double* right, size_t size_left, size_t size_right);

Complex* lnf_cplx_mul_cmplx(Complex* lnf, Complex* coef, size_t size_lnf);
Complex* lnf_cplx_mul_dbl(Complex* lnf, double* coef, size_t size_lnf);
double* lnf_dbl_mul_dbl(double* lnf, double* coef, size_t size_lnf);
Complex* lnf_dbl_mul_cmplx(double* lnf, Complex* coef, size_t size_lnf);

Complex lnf_cmplx_calc_cmplx(Complex* lnf, Complex* vrlbs, size_t size_lnf);
Complex lnf_cmplx_calc_dbl(Complex* lnf, double* vrlbs, size_t size_lnf);
Complex lnf_dbl_calc_cmplx(double* lnf, Complex* vrlbs, size_t size_lnf);
double lnf_dbl_calc_dbl(double* lnf, double* vrlbs, size_t size_lnf);

#endif