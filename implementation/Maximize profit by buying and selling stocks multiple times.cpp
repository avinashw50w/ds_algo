// Given the stock prices on different days, Maximize the profit by buying and selling stocks, 
//given the constraint that you should buy first before selling the stocks and there should not be any 
// overlapping transactions.
/* Take the example : 100 80 120 130 70 60 100 125
Just find increasing pairs ie, when a[i+1] > a[i], add a[i+1]-a[i] to the profit. */

int findProfit(int A[], int N)
{
	int profit = 0;

	REP(i, 0, N-1)
	{
		int currProfit = A[i] - A[i-1];
		if(currProfit > 0)
			profit += currProfit;
	}
	return profit;
}

///////////////////////////////////////////////////////////////////////////////
// to find the buying and selling days

struct Node {
	int buy;
	int sell;
};

vector<Node> findDays(int A[], int N){

	vector<Node> stocks;
	int buy, sell;

	for(int i = 0; i < N; ++i) {

		while(i < N-1 and A[i] >= A[i+1]) i++;

		if(i == N-1) break;

		buy = i;
		i++;

		while(i < N and A[i-1] < A[i]) i++;

		if(i == N) break;

		sell = i-1;

		stocks.push_back({buy, sell});
	}

	return stocks;
}

int main() {

	int A[] = { 100, 80, 120, 130, 70, 60, 100, 125 };

	int N = sizeof(A)/ sizeof(A[0]);

	vector<Node> stocks = findDays(A, N);

	for(Node I: stocks)
		cout << I.buy <<"-"<< I.sell <<", ";
}

