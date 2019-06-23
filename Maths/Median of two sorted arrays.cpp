/*Algorithm:

1) Calculate the medians m1 and m2 of the input arrays ar1[] 
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one    
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays 
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2*/

#include <iostream>
#include <algorithm>
using namespace std;

int median(int a[], int n) {
	if(n&1) return a[n/2];
	else return (a[n/2] + a[n/2-1])/2;
}

int getMedian(int a1[], int a2[], int n) {
	if(n == 0) return 0;
	if(n == 1) return (a1[0] + a2[0])/2;
	if(n == 2) return (max(a1[0], a2[0]) + min(a1[1], a2[1]))/2;

	int m1 = median(a1, n);
	int m2 = median(a2, n);

	if(m1 == m2) return m1;

	if(m1 < m2) {
		if( n & 1 ) return getMedian(a1 + n/2, a2, n - n/2);
		else return getMedian(a1 + n/2 - 1, a2, n - (n/2 - 1));
	} 

	else {
		if( n & 1 ) return getMedian(a1, a2 + n/2, n - n/2);
		else return getMedian(a1, a2 + n/2 - 1, n - (n/2 - 1));
	}
}

