/* 5 3 12 8 4 */

int solve(vector<int> a) {
    int best_with_stock = INT_MIN, best_without_stock = 0;

    for (int x: a) {
        best_with_stock = max(best_with_stock, best_without_stock - x);
        best_without_stock = max(best_without_stock, best_with_stock + x);
    }

    return max(best_without_stock, best_with_stock);
}