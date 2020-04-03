/*Three way partitioning of an array around a given range

Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided 
in three parts.
1) All elements smaller than lowVal come first.
2) All elements in range lowVal to highVVal come next.
3) All elements greater than highVVal appear in the end.
The individual elements of three sets can appear in any order.

Examples:

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  
        lowVal = 14, highVal = 20
Output: arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}*/

/*Use Dutch national flag algorithm*/

void arrange(int a[], int n, int lowVal, int highVal) {

	int i = 0, start = 0, end = n-1;
	
	while(i <= end) 
	{
		if(a[i] < lowVal) swap(a[i++], a[start++]);

		else if(a[i] > highVal) swap(a[i], a[end--]);

		else i++;
	}
}

/*
Time Complexity : O(n)
Auxiliary Space : O(1)

*/