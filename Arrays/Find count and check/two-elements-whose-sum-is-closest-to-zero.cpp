METHOD 2 (Use Sorting) 
Thanks to baskin for suggesting this approach. We recommend to read this post for background of this approach.

Algorithm 
1) Sort all the elements of the input array.
2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
3) sum = a[l] + a[r]
4) If sum is -ve, then l++
5) If sum is +ve, then r--
6) Keep track of abs min sum.
7) Repeat steps 3, 4, 5 and 6 while l < r
