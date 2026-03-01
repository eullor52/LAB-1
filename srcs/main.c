#include "lineform.h"
#include <stdio.h>

int error_work()
{
    int c;
    char choise;
    for(;;)
    {
        printf("Ошибка ввода! Попробовать еще раз? (Y/N): ");
        if (scanf("%c\n", &choise) != 1)
        {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        else if (choise != 'Y' && choise != 'N') 
        {
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (choise == 'N') return 1;
        else  
        {
            while ((c = getchar()) != '\n' && c != EOF);
            return 0;
        }
    }
}

int cmplx_input(Complex* lnf, size_t size)
{
    puts("Введите свободный член:");
    {
        for(;;)
        {
            puts("  Введите действительную часть:");
            if (scanf("%f", &(lnf->Re)) != 1)
            {
                if (error_work() == 1) return 1;
                else continue;
            }
            else break;
        }
        for(;;)
        {
            puts("  Введите мнимую часть:");
            if (scanf("%f", &(lnf->Im)) != 1)
            {
                if (error_work() == 1) return 1;
                else continue;
            }
            else break;
        }
    }
    for (int i = 1; i < size; i++)
    {
        printf("Коэффициент перед x%i:\n", i);
        for(;;)
        {
            puts("  Введите действительную часть:");
            if (scanf("%f", &((lnf + i)->Re)) != 1)
            {
                if (error_work() == 1) return 1;
                else continue;
            }
            else break;
        }
        for(;;)
        {
            puts("  Введите мнимую часть:");
            if (scanf("%f", &((lnf + i)->Im)) != 1)
            {
                if (error_work() == 1) return 1;
                else continue;
            }
            else break;
        }
    }
    return 0;
}

int dbl_input(double* lnf, size_t size)
{
    for(;;)
    {
        puts("Введите свободный член:");
        if (scanf("%f",&lnf) != 1)
        {
            if (error_work() == 1) break;
            else continue;
        }
        else break;
    }
    for (int i = 1; i < size; i++)
    {
        for(;;)
        {
            printf("Коэффициент перед x%d",i);
            if (scanf("%f", (lnf + i)) != 1)
            {
                if (error_work() == 1) break;
                else continue;
            }
            else break;
        }
    }
    return 0;
}

int lnf_input(void** lnf, char* type, size_t* size)
{
    double* d_lnf;
    Complex* c_lnf;

    for(;;)
    {
        puts("Введите количество переменных:");
        if (scanf("%d", size) != 1)
        {
            if (error_work() == 1) return 1;
            else continue;
        }
        else break;
    }
    for (;;)
    {
        puts("Введите тип значений (комплексные - с/действительные - d)");
        if (scanf("%c", type) != 1 || *type != 'c' && *type != 'd')
        {
            if (error_work() == 1) return 1;
            else continue;
        }
        else break;
    }
    if (*type == 'c')
    {
        c_lnf = malloc(sizeof(Complex)*(*size + 1));
        if (!c_lnf) return 2; //memory error
        if (cmplx_input(c_lnf, *size) == 1) return 1;
        *lnf = (void*)c_lnf;
    }
    else
    {
        d_lnf = (double*)malloc(sizeof(double)*(*size + 1));
        if (!d_lnf) return 2; //memory error
        if (dbl_input(d_lnf,*size) == 1) return 1;
        *lnf = (void*)d_lnf;
    }
}

int print_cmplx(Complex num)
{
    if (num.Re != 0 && num.Im != 0) 
    {
        printf("(%f + %f*i)", num.Re, num.Im);
        return 0;
    }
    else if(num.Re != 0) 
    {
        printf("%f",num.Re);
        return 0;
    }
    else if(num.Im != 0)
    {
        printf("%f*i",num.Im);
        return 0;
    }
    else return 1;
}

int cmplx_output(Complex* lnf, size_t size)
{
    int a = 1;
    if (print_cmplx(*lnf) != 0) printf(" + ");
    for (int i = 1; i < size; i++)
    {
        if (((lnf + i)->Re != 0 || (lnf + i)->Im != 0) && a == 0)
        {
            printf(" + ");
            a = 1;
        }
        if ((lnf + i)->Re != 0 && (lnf + i)->Im != 0)
        {
            printf("(");
            a *= print_cmplx(*(lnf + i));
            printf(") * x%d", i);
        }
        else
        {
            a *= print_cmplx(*(lnf + i));
            printf(" * x%d", i);
        }
    }
}

int lnf_output(void* lnf, char type, size_t size)
{

}

int main()
{
    for(;;)
    {
        int er;
        char choise1, choise2 = '0';
        size_t size1, size2;
        char type1, type2;
        void *lnf1, *lnf2;
        void *result;

        puts("Выберете операцию:");
        puts(" 1) - Сложение;");
        puts(" 2) - Вычитание;");
        puts(" 3) - Умножение на скаляр;");
        puts(" 4) - Вычисление значения;");

        if (scanf("%c", &choise1) != 1)
        {
            //clean_input_buffer
            if (error_work() == 1) return 1;
            else continue;
        }

        if (choise1 == '1')
        {
            Lnform1 lnf_calc;
            puts("Ввод первого слогаемого:");
            if (er = lnf_input(&lnf1, &type1, &size1) == 2) 
            {
                fprintf(stderr, "Ошибка выделениея памяти при вводе массива коэффициентов линейной формы.");
                return 1;
            }
            else if (er == 1) return 1;
            puts("Ввод второго слогаемого:");
            if (er = lnf_input(&lnf2, &type2, &size2) == 2) 
            {
                fprintf(stderr, "Ошибка выделениея памяти при вводе массива коэффициентов линейной формы.");
                return 1;
            }
            else if (er == 1) return 1;
            set_lnf1(&lnf_calc, lnf1, size1, type1, lnf2, size2, type2);
            if (lnf_calc.result_type == 'c')
            {
                Complex* result;
                result = (Complex*)lnf_calc.add_lnf;
                cmplx_output(result, size1);
            }
        }
    }
}