/*You are given a large array of 10,000,000 bits. Each bit is initially 0. You perform several operations of the type 
"Flip all the bits between start_index and end_index, inclusive". Given a sequence of several such operations, perform all 
the operations on the array. Finally, split the array into sets of 4 bits - first four, next four, then next four and so on. 
Each set can represent a hexadecimal integer. There will be exactly 2,500,000 hexadecimal integers. Calculate the frequency 
of each of the hexadecimal integers from '0' to 'f' among the 2,500,000 integers, and print it. See Input / Output and explanation 
of Sample Input / Output for clarity. 
Input 

The first line of input contains an integer T (1 ≤ T ≤ 10), the number of test cases. Then follows the description of T test cases. 
You should assume that the array has exactly 10,000,000 bits and that the bits are all unset at the start of each test case. 
The first line of each test case contains an integer N (1 ≤ N ≤ 10,000), the number of operations performed. The next N lines contain 
two integers separated by a space, the start_index and end_index for the respective operation. Note that the flip operation is performed 
from start_index to end_index, inclusive. Also, the array is 1-indexed - meaning, the smallest index is 1 and the largest index is 10,000,000. */

int a[10000007]={0};

int main(int argc, char const *argv[])
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		int n,b[16]={0};
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d %d",&x,&y);
			a[x]++;
			a[y+1]--;
		}
		for(int i=1;i<=10000000;i++)
			a[i]+=a[i-1];
		for(int i=1;i<=10000000;i++)
			a[i]=a[i]&1;
		int i=1,l=0,s=0;
		for(int i=1; i<=10000000;i+=4) {
			s = (a[i]<<3) + (a[i+1]<<2) + (a[i+2]<<1) + a[i+3];
			b[s]++;
		}
		for(i=0;i<=15;i++)
			printf("%d ",b[i] );
		printf("\n");
		for(i=1;i<=10000000;i++)
			a[i]=0;
	}
	return 0;	
}
