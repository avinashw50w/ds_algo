
void func(int a[], int n, int sum) 
{
	int front = 0;
	int prefix_sum = 0;
	
	for(int i = 0; i < n; ++i) {
		
		prefix_sum += a[i];
		
		while(prefix_sum > sum) 
			prefix_sum -= a[front++];
			
		if(prefix_sum == sum) cout << front << "-->" << i << endl;
	}
}
