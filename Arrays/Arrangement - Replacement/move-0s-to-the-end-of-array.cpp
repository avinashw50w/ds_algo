/*Given an array of random numbers, Push all the zero’s of a given array to the end of the array. 
// try to do it inplace
For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, 
it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. */

void move(int a[], int n) {

	int cnt = 0;

	for(int i = 0; i <n; ++i) 
		if(a[i] != 0)
			a[cnt++] = a[i];

	while(cnt < n) a[cnt++] = 0;
}