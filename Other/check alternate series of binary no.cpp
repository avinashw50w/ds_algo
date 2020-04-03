/*
 * C Program to Check whether the given Integer has an Alternate 
 * Pattern 
 */
#include <stdio.h>
 
void main()
{
    int num, x, y, count = 0;                             //tale an ex of 5=>101  which is alternate.its x value=010 , y=111 which is =7(odd) y+1=8(even)
    printf("enter the number:");                        //it means that if a binary no is alternate then its y value will always be odd
    scanf("%d", &num);
    x = num << 1;
    y = x ^ num;
    y = y + 1;
 
    /* Checks if the number is in powers of 2 */
    while ((y / 2) != 0)
    {
        if (y % 2 != 0)
        {
            count++;
            break;
        }
        else
        {
            y = y / 2;
        }
    }
    if (count)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
}
