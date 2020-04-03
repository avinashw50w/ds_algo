/*Find element at given index after a number of rotations
An array consisting of N integers is given. There are several Right Circular Rotations of range[L..R] that we perform. After performing these rotations, we need to find element at a given index.

Examples :

Input : arr[] : {1, 2, 3, 4, 5}
        ranges[] = { {0, 2}, {0, 3} }
        index : 1
Output : 3
Explanation : After first given rotation {0, 2}
                arr[] = {3, 1, 2, 4, 5}
              After second rotation {0, 3}
                arr[] = {4, 3, 1, 2, 5}
After all rotations we have element 3 at given
index 1.

Method : Efficient We can do offline processing after saving all ranges.
Suppose, our rotate ranges are : [0..2] and [0..3]
We run through these ranges from reverse.

After range [0..3], index 0 will have the element which was on index 3.
So, we can change 0 to 3, i.e. if index = left, index will be changed to right.
After range [0..2], index 3 will remain unaffected.

So, we can make 3 cases :
If index = left, index will be changed to right.
If index is not bounds by the range, no effect of rotation.
If index is in bounds, index will have the element at index-1.*/


int find(int a[], int ranges[][2], int idx) {

    int rotations = sizeof(ranges[0])/sizeof(ranges[0][0]);

    for (int i = rotations-1; i >= 0; --i) {
        int left = ranges[i][0], right = ranges[i][1];

        if (left <= idx && idx <= right) {
            if (idx == left) {
                idx = right;
            }
            else idx--;
        }
    }

    return a[idx];
}
