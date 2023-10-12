/*
https://cybergeeksquad.co/2023/03/shipment-imbalance-amazon-oa.html
You are given an integer array nums. The range of a subarray of nums is the difference between the 
largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

constraints:
1 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9

Example 1:

Input:
N = 3
arr[ ] = {1, 2, 3}
Output: 4
Explanation: The 6 subarrays of arr are the following :
{1 } , range = largest - smallest = 1 - 1 = 0 
{2 } , range = 2 - 2 = 0
{3 } , range = 3 - 3 = 0
{1, 2}, range = 2 - 1 = 1
{2, 3}, range = 3 - 2 = 1
{1, 2, 3}, range = 3 - 1 = 2
sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4
 

Example 2:

Input:
N = 4
arr[ ] = {-32, 0, -2, 72}
Output: 318
*/

// brute 
// T: O(N^2)
// S: O(1)
long solve(vector<int> a) {
	long sum = 0;
	int n = a.size();

	for (int i = 0; i < n; ++i) {
		long mx = a[i], mn = a[i];
		for (int j = i + 1; j < n; ++j) {
			mx = max(mx, a[i]);
			min = min(mn, a[i]);
			sum += mx - mn;
		}
	}

	return sum;
}

// Optimised
// T: O(N)
// S: O(N)
/*
We will take the contribution of each element as addition/subtraction in the final answer.
Standing on an element, if we see on the subsegments going on the right-hand side of it, the element will act as the minimum, till the elements are greater than it; i.e we need to find the next just smaller element than the current element on the right-hand side of it.
Similarly, it will act as the maximum, till the elements are smaller than it; i.e we need to find the next just greater element than the current element on the right-hand side of it.
The same is the case with the left-hand side.
Thus for a particular element, we will store the count of elements that are smaller(csl, csr), and that are greater(cgl, cgr),
for both the left-hand side and the right-hand side.
As we know the counts, then for a particular element we will add to the final answer – [currentElement * cgl * cgr].
As this will be the contribution of the current element being as a maximum in all the subsegments, in which it is occurring.
Similarly, for a particular element we will subtract from the final answer – [currentElement * csl * csr]. 
As this will be the contribution of the current element being as a minimum in all the subsegments, in which it is occurring.

*/
class Pair
{
public:
    int cgl, csl, cgr, csr;
    Pair()
    {
        this->cgl = 0;
        this->csl = 0;
        this->cgr = 0;
        this->csr = 0;
    }
};
void fill_cgl_cgr(int n, vector<int> &A, vector<Pair> &conf)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && A[i] >= A[st.top()])
        {
            conf[st.top()].cgr = i - st.top();
            st.pop();
        }
        if (!st.empty())
            conf[i].cgl = i - st.top();
        st.push(i);
    }
}
void fill_csl_csr(int n, vector<int> &A, vector<Pair> &conf)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && A[i] <= A[st.top()])
        {
            conf[st.top()].csr = i - st.top();
            st.pop();
        }
        if (!st.empty())
            conf[i].csl = i - st.top();
        st.push(i);
    }
}
long long ValueOfA(int n, vector<int> &A)
{
    long long ans = 0;
    vector<Pair> conf(n);
    for (int i = 0; i < n; i++)
    {
        conf[i].cgl = i + 1;
        conf[i].csl = i + 1;
        conf[i].cgr = n - i;
        conf[i].csr = n - i;
    }
    fill_cgl_cgr(n, A, conf);
    fill_csl_csr(n, A, conf);
    for (int i = 0; i < n; i++)
        ans += A[i] * (((long long)conf[i].cgl * conf[i].cgr) - ((long long)conf[i].csl * conf[i].csr));
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << ValueOfA(n, A);
}