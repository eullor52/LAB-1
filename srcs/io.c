#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int sprint_cmplx(char** str,Complex num)
{
    if (num.Im == num.Re == 0) return 0;

    if (num.Im != 0 && num.Re != 0)
    {
        char result[205];

        sprintf(result, "%.2f + %.2f*i", num.Re, num.Im);
        
        *str = result;

        return 2;
    }
    else if (num.Im == 0)
    {
        char result[100];

        sprintf(result, "%.2f", num.Re);

        *str = result;

        return 1;
    }
    else
    {
        char result[102];

        sprintf(result, "%.2f*i", num.Im);

        *str = result;

        return -1;
    }
}

char* generate_output(double* lnf, unsigned int size)
{
    char* result = malloc(sizeof(char)* 103 * size);
    char tmp[100];
    int p = 0;

    if (lnf[0] != 0) 
    {
        sprintf(tmp, "%.2f", lnf[0]);

        for (int i = 0; tmp[i] != '\0'; i++)
        {
            result[p] = tmp[i];
            ++p;
        }
        result[p++] = ' ';
        result[p++] = '+';
        result[p++] = ' ';
    }

    for (int i = 1; i < size; i++)
    {
        char vrbl[10];
        
        sprintf(tmp, "%.2f", lnf[i]);
        
        for (int k = 0; tmp[k] != '\0'; k++)
        {
            result[p++] = tmp[k];
        }

        result[p++] = '*';
        result[p++] = 'x';

        sprintf(vrbl, "%d", i);

        for (int x = 0; vrbl[x] != '\0'; x++)
        {
            result[p++] = vrbl[x];
        }
        if (i != size - 1)
        {
            result[p++] = ' ';
            result[p++] = '+';
            result[p++] = ' ';
        }
    }
    result[p++] = '\0';

    return result;
}