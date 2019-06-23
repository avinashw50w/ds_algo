// A O(n^2) time and O(1) extra space solution
//Longest even length substring(such that sum of its first and second half is same
#include<bits/stdc++.h>
using namespace std;
 
int findLength(string str, int n)
{
    int ans = 0; // Initialize result
 
    // Consider all possible midpoints one by one
    for (int i = 0; i <= n-2; i++)
    {
        /* For current midpoint 'i', keep expanding substring on
           both sides, if sum of both sides becomes equal update
           ans */
        int l = i, r = i + 1;
 
        /* initialize left and right sum */
        int lsum = 0, rsum = 0;
 
        /* move on both sides till indexes go out of bounds */
        while (r < n && l >= 0)
        {
            lsum += str[l] - '0';
            rsum += str[r] - '0';
            if (lsum == rsum)
                ans = max(ans, r-l+1);
            l--;
            r++;
        }
    }
    return ans;
}

int main()
{
    string str = "123123";
    cout << "Length of the substring is " << findLength(str, str.length());
    return 0;
}
