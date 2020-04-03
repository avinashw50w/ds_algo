/*Given a number your task is to complete the function convertFive which takes an integer n as argument and replaces all zeros in the number n with 5 .
Your function should return the converted number .

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow . Each test case contains a single 
integer n denoting the number.

Output:
The output of the function will be an integer where all zero's are converted to 5 .

Constraints:
1<=T<100
1<=n<=10000

Example:
Input
2
1004
121

Ouput
1554
121
*/
/*you are required to complete this method*/
int convertFive(int n)
{
    int five = 5;
    
    string num = to_string(n);
    for(int i = num.size()-1; i>=0; --i) {
        if(num[i] == '0') n += five;
        
        five *= 10;
    }
    return n;
}

///////////////////////////////////////////////////////////
// recursive //

// C program to replace all ‘0’ with ‘5’ in an input Integer
#include<stdio.h>
 
// A recursive function to replace all 0s with 5s in an input number
// It doesn't work if input number itself is 0.
int convert0To5Rec(int num)
{
    // Base case for recursion termination
    if (num == 0)
        return 0;
 
    // Extraxt the last digit and change it if needed
    int digit = num % 10;
    if (digit == 0)
        digit = 5;
 
    // Convert remaining digits and append the last digit
    return convert0To5Rec(num/10) * 10 + digit;
}
 
// It handles 0 and calls convert0To5Rec() for other numbers
int convert0To5(int num)
{
    if (num == 0)
       return 5;
    else return  convert0To5Rec(num);
}