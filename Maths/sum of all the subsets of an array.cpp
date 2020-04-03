/*sum of all the subsets of an array.
eg. arr = {1,2,3}
subsets = 1, 2, 3, {1,2}, {2,3}, {1,3}, and {1,2,3}
K = 1+2+3+(1+2)+(2+3)+(1+3)+(1+2+3), 
then how to find K ? 

a : a
a,b : a+b+ a+b = 2(a+b)
a,b,c : a+b+c+a+b+a+c+b+c+a+b+c = 4a+4b+4c = 4(a+b+c)
a,b,c,d : a+b+c+d + a+b + a+c + a+d + b+c + b+d + c+d + a+b+c + a+b+d + a+c+d + b+c+d + a+b+c+d = 8a + 8b + 8c + 8d

it means for a set of size n, sum of all the subsets = 2^(n-1) * (a1 + a2 + a3 + ... + an)
*/

