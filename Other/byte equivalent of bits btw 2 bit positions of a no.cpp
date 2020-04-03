/*
 * C Program takes Byte as Input and returns all the Bits between 
 * given Positions
 */
#include <stdio.h>
 
int number_between_bit_positions(int,int,int);
int result = 0;
 
int main()
{
    int number, start_pos, end_pos;
 
    printf("\nEnter the number");
    scanf("%d", &number);
    printf("\nEnter the position of a and b");
    scanf("%d %d", &start_pos, &end_pos);
    result = number_between_bit_positions(number, start_pos, end_pos);
    printf("Byte Equivalent of bits between %d and %d positions %d", start_pos, end_pos, result);
}
 
int number_between_bit_positions(int number, int start_pos , int end_pos)
{
    int i, j, shift_num, res_val;
 
    /*
     * Right shift to the specified start position,take the corresponding bits using &
     * Left shift to locate the bits in their respective positions
     */
    for (i = start_pos, j = 0;i <= end_pos;i++,j++)
    {
        shift_num = number >> i;
        res_val = shift_num & 1;
        res_val = res_val << j;
        result += res_val;
    }
    return result;
}
