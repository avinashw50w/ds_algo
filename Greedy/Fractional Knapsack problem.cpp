/*Fractional Knapsack Problem
Given weights and values of n items, we need to put these items in a knapsack of
capacity W to get the maximum total value in the knapsack.

In the 0-1 Knapsack problem, we are not allowed to break items.
We either take the whole item or don’t take it.

Input:
  Items as (value, weight) pairs
  arr[] = {{60, 10}, {100, 20}, {120, 30}}
  Knapsack Capacity, W = 50;
Output:
  Maximum possible value = 220
  by taking items of weight 20 and 30 kg */

/*sort the items in order of their val/weight ratio*/

struct Item {
    int val;
    int wt;
    Item(int val, int wt) : val(val), wt(wt) {}
};

double fractionalKnapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(),
    [](auto & a, auto & b) { return (double)a.val / a.wt > (double)b.val / b.wt; });

    double finalValue = 0;
    int currWeight = 0;

    for (int i = 0; i < items.size(); ++i) {
        if (currWeight + items[i].wt <= W) {
            currWeight += items[i].wt;
            finalValue += items[i].val;
        }
        else {
            int remaining = W - currWeight;
            finalValue += items[i].val * ((double) remaining / items[i].wt);
            break;
        }
    }

    return finalValue;
}
