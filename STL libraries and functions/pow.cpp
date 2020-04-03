#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
 
#pragma STDC FENV_ACCESS ON
int main(void)
{
    // typical usage
    printf("pow(2, 10) = %f\n", pow(2,10));
    printf("pow(2, 0.5) = %f\n", pow(2,0.5));
    printf("pow(-2, -3) = %f\n", pow(-2,-3));
    // special values
    printf("pow(-1, NAN) = %f\n", pow(-1,NAN));
    printf("pow(+1, NAN) = %f\n", pow(+1,NAN));
    printf("pow(INFINITY, 2) = %f\n", pow(INFINITY, 2));
    printf("pow(INFINITY, -1) = %f\n", pow(INFINITY, -1));
    // error handling 
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("pow(-1, 1/3) = %f\n", pow(-1, 1.0/3));
    if(errno == EDOM)         perror("    errno == EDOM");
    if(fetestexcept(FE_INVALID)) puts("    FE_INVALID raised");
 
    feclearexcept(FE_ALL_EXCEPT);
    printf("pow(-0, -3) = %f\n", pow(-0.0, -3));
    if(fetestexcept(FE_DIVBYZERO)) puts("    FE_DIVBYZERO raised");
}
Possible output:
pow(2, 10) = 1024.000000
pow(2, 0.5) = 1.414214
pow(-2, -3) = -0.125000
pow(-1, NAN) = nan
pow(+1, NAN) = 1.000000
pow(INFINITY, 2) = inf
pow(INFINITY, -1) = 0.000000
pow(-1, 1/3) = -nan
    errno == EDOM: Numerical argument out of domain
    FE_INVALID raised
pow(-0, -3) = -inf
    FE_DIVBYZERO raised
