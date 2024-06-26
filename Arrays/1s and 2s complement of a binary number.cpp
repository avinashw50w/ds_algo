
char flip(char c) {return (c == '0')? '1': '0';}

void printOneAndTwosComplement(string bin)
{
    int n = bin.length();
    int i;
    
    string ones, twos;
    ones = twos = "";
    
    //  for ones complement flip every bit
    for (i = 0; i < n; i++)
        ones += flip(bin[i]);
    
    twos = ones;
    for (i = n - 1; i >= 0; i--)
    {
        if (ones[i] == '1')
            twos[i] = '0';
        else
        {
            twos[i] = '1';
            break;
        }
    }
    
    // If No break : all are 1  as in 111  or  11111;
    // in such case, add extra 1 at beginning
    if (i == -1)
        twos = '1' + twos;
    
    
    cout << "1's complement: " << ones << endl;
    cout << "2's complement: " << twos << endl;
}