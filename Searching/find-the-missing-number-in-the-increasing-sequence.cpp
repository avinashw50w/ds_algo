/*If we traverse the given sequence number by number starting from the element at the 0th index, we can easily tell 
which number is missing by looking at the difference between the number at index 'i' and number at index 'i-1'. 
If this difference is greater than 1, we know that we have identified a missing number. For example, 
for sequence {1,2,3,4,6,7,8}, difference between number 6 and number 4 is 2 and hence we say that missing number is 5. 
BUT, as per the problem statement we are not supposed to traverse the sequence in linear fashion. 
Let's look at an optimized approach which runs in log(n) time.

Correctly placed numbers: For a number 'i', if all the 'i-1' numbers appearing before it are present in the given sequence then we say 
that the number 'i' is correctly placed in the given sequence. Because the given sequence is stored in an array which starts from index 0,
 we can easily check if a number is correctly placed by checking if its index is equal to the value of that number minus 1. For example, 
 for sequence {1,2,3,4,6,7,8}, if you consider number 4 which is correctly placed, its index is 3 which is 4 minus 1. Same is the case for 
 numbers 1,2 and 3. But for numbers 6,7 and 8 which are not correctly placed(since number 5 which appears before them is missing), 
 their respective indices are not equal to their respective values minus 1. 

Idea: Now using the above idea of correctly placed numbers, to find out the missing number we find the first number from the left in 
the given sequence(say number 'j') which is incorrectly placed. Once we find this number 'j', we know that the missing number 
must be 'j-1' since number 'j' is the first element from the left which is incorrectly placed in the given sequence.  

Algorithm: We find this above defined number 'j' using binary search algorithm. If 'array' stores the given sequence and if function 
'findMissingElement(int[] array, int low, int high)' is used to find the missing number in this 'array' with its first element at 
index 'low' and its last element at index 'high', then the steps used by this function are as following - 

1. If low > high, then this is invalid input case. To indicate that, return -1.
2. If low == high, then we have found the first element which is incorrectly placed. Return 'array[high] - 1' in this case.
Step #1 and step #2 are base cases for this binary search. Recursive steps are as following.

3. Calculate mid as (low + high)/2. 
a. If array[mid] is correctly placed, then we need to search for the first incorrectly placed element in the higher half of 
the array(from 'mid + 1' to high). Note that since array[mid] is correctly placed it cannot be the first incorrectly placed 
element and therefore we exclude it from the search by making low = mid + 1.
b. If array[mid] is incorrectly placed, then we need to search for the first incorrectly placed element in the lower half of 
the array(from low to mid). Note that since array[mid] could also be the first element which is incorrectly placed, we cannot 
exclude it from the search and hence we make high = mid(and not 'mid - 1').
c. With the modified array boundary in above steps, we make recursive call findMissingElement(array, low, high) to find the missing number.*/


bool correct(int i, int n) { return i == (n-1); }


int find(int A[], int L, int R)
{
	if(L > R) return -1;

	if(correct(R, A[R])) {
		cout << "No missing number\n";
		return 0;
	}

	if(L == R) return A[R]-1;

	int mid = (L+R)>>1;

	if(!correct(mid, A[mid])) R = mid;

	else L = mid+1; 

	return find(A, L, R);
}

