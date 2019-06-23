/*Raman loves Mathematics a lot. One day his maths teacher gave him an interesting problem.

He was given an array 'A' consisting of 'n' integers, he was needed to find the maximum value of the following expression:

|Ai - Aj| + |i - j|

where, 0<= i,j <n and Ai, Aj are the Array elements.

Input:

First line of input contains an integer T denoting number of test cases.
Each test case contains two lines, first line contains integer n where n is the number of elements in array
Second line contains n space separated integers Ai.
Output:

Print the maximum value of the above give expression, for each test case separated in a new line.

The given questions asks us to find the maximum value of |Ai - Aj| + |i-j|,

A simple solution will be to iterating in two for loops and get the answer, but since constraints are too large and time limit is strict, it will not pass.

So, let us try to do this in other way. First of all lets make the four equations by removing the mod , Following four equations will be formed, and we need to find the maximum value of any of these equation,that will be our answer :

Ai - Aj + i - j = (Ai+i) - (Aj+j) ....(i)
Ai - Aj - i + j = (Ai-i) - (Aj-j) .... (ii)
-Ai + Aj + i - j = -(Ai-i) + (Aj-j) .... (iii)
-Ai + Aj - i + j = -(Ai+i) + (Aj+j) .... (iv)
A simple observation is that the equation (i) and (iv) are identical, similarly equations (ii) and (iii) are identical.

Now, how do we find the maximum value of the given equations ? One approach is to form two arrays ,

First_Array[], it will store (Ai+i), 0<=i< n
Second_Array[],it will store values of (Ai-i), 0<=i< n
Now, our task is easy we just need to find the maximum difference b/w two values in the above created two arrays.

For that, we find maximum value and minimum value in First_Array, and store their difference;

ans1= (maximum value in First Array - minimum value in First Array);

Similarly, we need to find the maximum value and minimum value in Second_Array, and store their difference;

ans2= (maximum value in Second Array - minimum value in Second Array);

Desired Answer = max(ans1,ans2) ;*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 5;
int t, n, a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t; 
    while(t--) {
        cin >> n;
        
        int mx1 = -1, mx2 = -1, mn1 = 1e9, mn2 = 1e9;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
            a[i] += i;
            b[i] -= i;
            
            mx1 = max(mx1, a[i]);
            mx2 = max(mx2, b[i]);
            mn1 = min(mn1, a[i]);
            mn2= min(mn2, b[i]);
        }
        
        cout << max(abs(mx1-mn1), abs(mx2-mn2)) << endl;
    }
}