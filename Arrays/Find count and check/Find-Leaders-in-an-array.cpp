/*Leaders in an array
Write a program to print all the LEADERS in the array. An element is leader if it is greater 
than all the elements to its right side. And the rightmost element is always a leader. 
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

Let the input array be arr[] and size of the array be size.

// simple method //
void printLeaders(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j;
        for (j = i+1; j < size; j++)
        {
            if (arr[i] <= arr[j])
                break;
        }    
        if (j == size) // the loop didn't break
            cout << arr[i] << " ";
  }
}

/* efficient method : Scan all the elements from right to left in array and keep track of maximum till now. 
When maximum changes it’s value, print it. */

void printLeaders(int a[], int size) {
	
	int currMax = a[n-1];

	cout << currMax << " ";

	for(int i = n-2; i >= 0; --i) {
		if(a[i] > currMax) {
			currMax = a[i];
			cout << currMax << " ";
		}
	}
}

