/*Method 5 (Use XOR)
Let x and y be the desired output elements.
Calculate XOR of all the array elements.

     xor1 = arr[0]^arr[1]^arr[2].....arr[n-1]
XOR the result with all numbers from 1 to n

     xor1 = xor1^1^2^.....^n
In the result xor1, all elements would nullify each other except x and y, ie, xor1 = x ^ y. All the bits that are set in xor1 
will be set in either x or y. So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 
and divide the elements of the array in two sets – one set of elements with same bit set and other set with same bit not set. 
By doing so, we will get x in one set and y in another set. Now if we do XOR of all the elements in first set, we will get x, 
and by doing same in other set we will get y.*/

vector<int> Solution::repeatedNumber(const vector<int>& a) {
    int n = a.size();
    
    long long xorr = 0;
    
    for(int i = 0; i < n; ++i) xorr ^= a[i];
    
    for(int i = 1; i <= n; ++i) xorr ^= i;
    
    long long x = 0, y = 0, set_bit;
    
    set_bit = xorr & -xorr; // take the last set bit of xorr
    
    // x contain the xor of all the numbers of the array having the set_bit set
    // and y contains xor of the other numbers of the array
    for(int i = 0; i < n; ++i)
        
        if(a[i] & set_bit) x ^= a[i];
        
        else y ^= a[i];
        
    for(int i = 1; i <= n; ++i)
        
        if(i & set_bit) x ^= i;
        
        else y ^= i;
        
    int cnt = 0;
    
    for(int i = 0; i < n; ++i) if(a[i] == x) cnt++;
    // if x is not the repeating number, then swap x and y, because we need 
    // the result in the order ( repeating number, missing number )
    if(cnt == 0) swap(x, y);  
    
    vector<int> res = {x, y};
    
    return res;
}
