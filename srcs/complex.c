#include "complex.h"

Complex sum_cmplx(Complex* right, Complex* left)
{
    Complex result;
    result.Re = right->Re + left->Re;
    result.Im = right->Im + left->Im;
    return result;
}

Complex dif_cmplx(Complex* right, Complex* left)
{
    Complex result;
    result.Re = right->Re - left->Re;
    result.Im = right->Im - left->Im;
    return result;
}

Complex mul_cmplx(Complex* right, Complex* left)
{
    Complex result;
    result.Re = right->Re * left->Re + right->Im * left->Im;
    result.Im = right->Re * left->Im + right->Im * left->Re;
    return result;
}