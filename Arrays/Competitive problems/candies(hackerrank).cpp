/*Alice is a kindergarten teacher. She wants to give some candies to the children in her class.
All the children sit in a line and each of them has a rating score according to his or her 
performance in the class.  Alice wants to give at least 1 candy to each child. If two children 
sit next to each other, then the one with the higher rating must get more candies. Alice wants 
to minimize the total number of candies she must buy.

eg. arr = [4,6,4,5,6,2],
She gives the students candy in the following minimal amounts: [1,2,1,2,3,1]. She must buy a 
minimum of 10 candies.
*/

ll solve(vector<int> a) {
    int n = a.size();
    vector<int> c(n, 1); // everyone gets atleast 1 candy
    for (int i = 1; i < n; ++i) {
        // current child gets one extra candy than the previous one if he's better
        if (a[i] > a[i-1]) c[i] = c[i-1] + 1; 
    }

    for (int i = n-2; i >= 0; --i) {
        if (a[i] > a[i+1] and c[i] < c[i+1] + 1)
            c[i] = c[i+1] + 1;
    }

    ll sum = 0;
    for (int e: c) sum += e;

    return sum;
}