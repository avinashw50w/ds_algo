/*Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements. 
If there are multiple answers, then print any of them.*/
// Find four different elements a,b,c and d of array such that
// a+b = c+d
#include<bits/stdc++.h>
using namespace std;
 
bool findPairs(int arr[], int n)
{
    // Create an empty Hash to store mapping from sum to
    // pair indexes
    map<int, pair<int, int> > Hash;
 
    // Traverse through all possible pairs of arr[]
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // If sum of current pair is not in hash,
            // then store it and continue to next pair
            int sum = arr[i] + arr[j];
            if (Hash.find(sum) == Hash.end())
                Hash[sum] = make_pair(i, j);
 
            else // Else (Sum already present in hash)
            {
                // Find previous pair
                pair<int, int> pp = Hash[sum];// pp->previous pair
 
                // Since array elements are distinct, we don't
                // need to check if any element is common among pairs
                cout << "(" << arr[pp.first] << ", " << arr[pp.second]
                     << ") and (" << arr[i] << ", " << arr[j] << ")\n";
                return true;
            }
        }
    }
 
    cout << "No pairs found";
    return false;
}