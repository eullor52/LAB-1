#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
    double Re;
    double Im;
}Complex;

Complex sum_cmplx(Complex* right, Complex* left);
Complex dif_cmplx(Complex* right, Complex* left);
Complex mult_cmplx(Complex* right, Complex* left);

#endif