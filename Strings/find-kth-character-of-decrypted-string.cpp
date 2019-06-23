/*Given an encoded string where repetitions of substrings are represented as substring followed by count of substrings. 
For example, if encrypted string is “ab2cd2″ and k=4 , so output will be ‘b’ because decrypted string is “ababcdcd” and 4th character is ‘b’.*/

// Function to find K'th character in Encoded String
char encodedChar(string str,int k)
{
    // expand string variable is used to
    // store final string after decompressing string str
    string expand = "";
 
    string temp;  // Current substring
    int freq = 0; // Count of current substring
 
    for (int i=0; str[i]!='\0'; )
    {
        temp = ""; // Current substring
        freq = 0; // count frequency of current substring
 
        // read characters untill you find a number
        // or end of string
        while (str[i]>='a' && str[i]<='z')
        {
            // push character in temp
            temp.push_back(str[i]);
            i++;
        }
 
        // read number for how many times string temp
        // will be repeated in decompressed string
        while (str[i]>='1' && str[i]<='9')
        {
            // generating frequency of temp
            freq = freq*10 + str[i] - '0';
            i++;
        }
 
        // now append string temp into expand
        // equal to its frequency
        for (int j=1; j<=freq; j++)
            expand.append(temp);
    }
 
    // this condition is to handle the case
    // when string str is ended with alphabeds
    // not with numeric value
    if (freq==0)
        expand.append(temp);
 
    return expand[k-1];
}
 
// Driver program to test the string
int main()
{
    string str = "ab4c12ed3";
    int k = 21;
    cout << encodedChar(str, k) << endl;
    return 0;
}

/*
Run on IDE
Output:

 e


 */