#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "complex.h"
#include <stdlib.h>

void* lnf_cmplx_add_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_cmplx_add_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_dbl_add_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_cmplx_dif_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_cmplx_dif_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_dbl_dif_cmplx(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_dbl_add_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right);
void* lnf_dbl_dif_dbl(void* v_left, void* v_right,  size_t size_left, size_t size_right);

void* lnf_cmplx_mul_cmplx(void* v_lnf, void* v_coef, size_t size_lnf);
void* lnf_cmplx_mul_dbl(void* v_lnf, void* v_coef, size_t size_lnf);
void* lnf_dbl_mul_dbl(void* v_lnf, void* v_coef, size_t size_lnf);
void* lnf_dbl_mul_cmplx(void* v_lnf, void* v_coef, size_t size_lnf);

void* lnf_cmplx_calc_cmplx(void* v_lnf, void* v_vrlbs, size_t size_lnf);
void* lnf_cmplx_calc_dbl(void* v_lnf, void* v_vrlbs, size_t size_lnf);
void* lnf_dbl_calc_cmplx(void* v_lnf, void* v_vrlbs, size_t size_lnf);
void* lnf_dbl_calc_dbl(void* v_lnf, void* v_vrlbs, size_t size_lnf);

#endif