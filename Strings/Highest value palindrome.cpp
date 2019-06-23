/*Given a numeric string s of size n. We have to perform maximum k operations to make the string palindrome.
Operation is to change one letter at a time.
Print the higest number possible by a maximum of k such operations
eg. 5 2
1 2 3 8 9 => 8 9 3 8 9

explanation: 
take two pointers left = 0 and right = n-1;
compare left and right and change the smaller letter to the larger one and decrement k by 1.
then do left++ and right--;

if k becomes -ve, then a palindrome cannot be formed from k operations, so print -1

Now, if some k are left, then use the remaining operations to replace the letters to 9
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

string solve() {
    
    int l = 0, r = n-1;
    
    string a = s;
    int mark[n] = {};
    
    while(l <= r) {
        if (l == r) {
            break;
        }
        
        if (a[l] < a[r]) {
            a[l] = a[r];
            mark[l] = 1;
            k--;
        } 
        else if (a[l] > a[r]) {
            a[r] = a[l];
            mark[r] = 1;
            k--;
        }
        
        l++;
        r--;
    }
    
    if (k < 0) {
        return "-1";
    }
    
    l = 0; r = n-1;
    
    while (l <= r) {
        if (l == r) {
            if (a[l] < '9' and k >= 1) {
                a[l] = '9';
                k--;
                break;
            }
        }
        
        if (a[l] < '9') {
            if (mark[l] == 0 and mark[r] == 0 and k >= 2) {
                a[l] = a[r] = '9';
                k -= 2;
            } 
            else if ((mark[l] == 1 or mark[r] == 1) and k >= 1) {
                a[l] = a[r] = '9';
                k--;
            }
        }
        
        l++; r--;
    }
    
    return a;
}

int main() {
    cin >> n >> k;
    cin >> s;
    
    cout << solve() << endl;
}

