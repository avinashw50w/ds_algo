/*
https://cybergeeksquad.co/2023/03/max-profit-amazon-oa-solution.html
An Amazon seller is deciding which of their products to invest in for the next quarter to maximize their profits.
They have each of their products listed as segments of a circle. Due to varying market conditions, 
the products do not sell consistently. The seller wants to achieve maximum profit using limited resources for investment. 
The product list is segmented into a number of equal segments, and a projected profit is calculated for each segment. 
The projected profit is the cost to invest versus the sale price of the product. 
The seller has chosen to invest in a number of contiguous segments along with those opposite. 
Determine the maximum profit the seller can achieve using this approach.

For example, the product list Is divided into n = 6 sections and will select k = 2 contiguous sections and those 
opposite to invest in. The profit estimates are profit = [1, 5, 1, 3, 7, -3] respectively. 
The diagrams below show the possible choices with profits[0] at the 9 o’clock position and filling counterclockwise.
*/
// efficient harvest
int getQuerySum(vector<int> &prefixSum, int a, int b) // function to get interval sum in constant time
{
    if(a <= b)
        return prefixSum[b] - (a >= 1 ? prefixSum[a-1] : 0);
    
    return getQuerySum(prefixSum, a, prefixSum.size()-1) + getQuerySum(prefixSum, 0, b); 
}
int findMaxProfit(vector<int> profit, int n, int k)
{
    vector<int> prefixSum;
    
    int sum = 0, maxProfit = INT_MIN, l = (n >> 1);
    
    for(auto &x : profit)
    {
        sum += x;
        prefixSum.push_back(sum);
    }
    
    for(int i = 0;i < (n >> 1); i++)
    {
        int temp = getQuerySum(prefixSum, i, i + k - 1) + getQuerySum(prefixSum, (i + l) % n, (i + l + k - 1) % n);
        
        maxProfit = max(maxProfit, temp);
    }
    
    return maxProfit;
}
int main()
{
    cout<<findMaxProfit({1, 5, 1, 3, 7, -3}, 6, 2)<<"\n"; // 16
    cout<<findMaxProfit({-3, -6, 3, 6}, 4, 1)<<"\n"; // 0
    cout<<findMaxProfit({3, -5}, 2, 1)<<"\n"; // -2
    return 0;
}