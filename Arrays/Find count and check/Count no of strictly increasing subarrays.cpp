/*count number of strictly increasing subrrays in an array*/

int count(vector<int> A) {

    int len = 1, count = 0;

    for (int i = 1; i < A.size(); ++i) {
        if (A[i-1] < A[i]) count += (len++);
        else len = 1;
    }

    return count;
}