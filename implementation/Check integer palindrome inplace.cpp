/*We could construct a better and more generic solution. One pointer is that, we must start comparing the digits somewhere. 
And you know there could only be two ways, either expand from the middle or compare from the two ends.

It turns out that comparing from the two ends is easier. First, compare the first and last digit. If they are not the same, 
it must not be a palindrome. If they are the same, chop off one digit from both ends and continue until you have no digits left, 
which you conclude that it must be a palindrome.

Now, getting and chopping the last digit is easy. However, getting and chopping the first digit in a generic way requires some thought. 
The solution below takes care of it.*/

int isIntPalindrome(int x)
{
    if (x < 0)
    return 0;
    int div = 1;
    while (x / div >= 10)
    {
        div *= 10;
    }
 
    while (x != 0)
    {
        int l = x / div;
        int r = x % 10;
        if (l != r)
            return 0;
        x = (x % div) / 10;  // stripping off from both sides
        div /= 100;
    }
    return 1;
}