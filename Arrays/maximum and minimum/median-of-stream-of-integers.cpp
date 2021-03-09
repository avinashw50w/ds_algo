typedef priority_queue<int> maxHeap; // max heap
typedef priority_queue<int, vector<int>, greater<int>> minHeap; // min heap

void addNumber(int n, maxHeap leftHeap, minHeap rightHeap)
{
	if(leftHeap.emtpy() || n < leftHeap.top())
		leftHeap.push(n);
	else
		rightHeap.push(n);
}

void rebalance(maxHeap leftHeap, minHeap rightHeap)
{
	if(leftHeap.size() - rightHeap.size() >= 2) {
		rightHeap.push(leftHeap.top());
		leftHeap.pop();
	}
	else if(rightHeap.size() - leftHeap.size() >= 2) {
		leftHeap.push(rightHeap.top());
		rightHeap.pop();
	}
}

int getMedian(maxHeap leftHeap, minHeap rightHeap) 
{
	if(leftHeap.size() == rightHeap.size())
		return (leftHeap.top() + rightHeap.top()) >> 1;
	if(leftHeap.size() - rightHeap.size() == 1)
		return leftHeap.top();
	if(rightHeap.size() - leftHeap.size() == 1)
		return rightHeap.top();
}

void printMedian() {
	maxHeap leftHeap;
	minHeap rightHeap;

	int n;

	while(cin >> n) {
		addNumber(n, leftHeap, rightHeap);
		rebalance(leftHeap, rightHeap);
		cout << getMedian(leftHeap, rightHeap) << " ";
	}
}

/////////////////////////////////////////////////////////////////////

double average(int n1, int n2)
{
	return (n1 + n2) / 2;
}
 
/* we can use a max heap on left side to represent elements that are less than effective median, 
and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element. 
When both heaps contain same number of elements, we pick average of heaps root data as effective median. 
When the heaps are not balanced, we select effective median from the root of heap containing more elements.*/
// This method maintains the condition that maxHeap size 
// is always greater than or equal to minHeap size.
void addNewNumber(int randomNumber, priority_queue<int, vector<int>, greater<int>>& minHeap, priority_queue<int, vector<int>, less<int>>& maxHeap)
{
	if(minHeap.size() == maxHeap.size())
	{
		if((!minHeap.empty()) && (randomNumber > minHeap.top()))
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(randomNumber);
		}
		else
		{
			maxHeap.push(randomNumber);
		}
	}
	else
	{
		if(randomNumber > maxHeap.top())
		{
			minHeap.push(randomNumber);
		}
		else
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(randomNumber);
		}
	}
}
 
double getMedian(priority_queue<int, vector<int>, greater<int>> minHeap, priority_queue<int, vector<int>, less<int>> maxHeap)
{
	// maxHeap is always at least as big as minHeap.
	// So if maxHeap is empty, then minHeap is empty too.
	if(maxHeap.empty())
		return 0;
 
	// If both maxHeap and minHeap have same sizes 
	// then return average of their top elements.
	if(maxHeap.size() == minHeap.size())
		return average(maxHeap.top(), minHeap.top());
 
	// if maxHeap and minHeap are of different sizes then
	// maxHeap must have one extra element. So return top of maxHeap.
	return maxHeap.top();
}
 
void printMedian(int arr[], int size)
{
    double median = 0; // effective median
    priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;
 
	for(int i = 0; i < size; i++)
    {
		addNewNumber(arr[i], minHeap, maxHeap);
        median = getMedian(minHeap, maxHeap);
        cout << median << endl;
    }
}
 
int main()
{
	int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    // In lieu of A, we can also use data read from a stream
    printMedian(arr, size);
 
    return 0;
}

////////////////////////////////////////////////////////////

