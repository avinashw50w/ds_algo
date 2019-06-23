#include <iostream>
#include <cstring>
using namespace std;

void DoCombine(char in[], char out[], int length, int recursLev, int start)
{
    for(int i = start; i < length; i++) {
        out[recursLev] = in[i];     //Select the current letter
        out[recursLev + 1] = '\0';  //tack on NULL for printf
        printf("%s\n", out);

        if(i < (length - 1))
            DoCombine(in, out, length, recursLev + 1, i + 1);
    }
}

int combine(char inString[])
{
    int length;
    length = strlen(inString);
    char out[length];

    DoCombine(inString, out, length, 0, 0);

    return 1;
}

int main()
{
    combine("abcd");
    return 0;
}