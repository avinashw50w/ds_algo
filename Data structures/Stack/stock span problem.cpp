/*we have a series of n daily price quotes
for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days
just before the given day, for which the price of the stock on the current day is
less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}*/

// A stack based efficient method to calculate stock span values
vector<int> stockSpan(vector<int> price)
{
   int n = price.size();
   vector<int> span(n, 1);
   stack<int> st;

   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && price[st.top()] <= price[i])
         st.pop();

      span[i] = st.empty() ? (i + 1) : (i - st.top());

      st.push(i);
   }

   return span;
}

int main() {
   vector<int> p = {100, 80, 60, 70, 60, 75, 85};
   vector<int> s = stockSpan(p);
   for (int e : s) cout << e << " ";
}
