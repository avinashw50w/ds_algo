/*It's New Year's Day and everyone's in line for the Wonderland rollercoaster
 ride! There are a number of people queued up, and each person wears a sticker
  indicating their initial position in the queue. Initial positions increment
  by 1 from 1 at the front of the line to n at the back.

Any person in the queue can bribe the person directly in front of them to swap
positions. If two people swap positions, they still wear the same sticker
denoting their original places in line. One person can bribe at most two others.
For example, if n = 8 and Person 5 bribes Person 4, the queue will look like
this: 1 2 3 5 4 6 7 8.

Fascinated by this chaotic queue, you decide you must know the minimum number of
bribes that took place to get the queue into its current state!

Function Description

Complete the function minimumBribes in the editor below. It must print an integer
representing the minimum number of bribes necessary, or Too chaotic if the line
configuration is not possible.

minimumBribes has the following parameter(s):

q: an array of integers
Input Format

The first line contains an integer t, the number of test cases.

Each of the next  pairs of lines are as follows:
- The first line contains an integer t, the number of people in the queue
- The second line has n space-separated integers describing the final state of the queue.

Constraints
1 ≤ t ≤ 10
1 ≤ N ≤ 10^5

IDEA: find the no of elements less than a[i] which lies on the right side of a[i], and if the no
of elements are <= 2 then adds it up otherwise output "Too chaotic"
*/

void minimumBribes(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == i + 1) continue;
        if (i - 1 >= 0 and a[i - 1] == i + 1) {
            cnt++;
            swap(a[i - 1], a[i]);
        }
        // 5 3 4
        else if (i - 2 >= 0 and a[i - 2] == i + 1) {
            cnt += 2;
            a[i - 2] = a[i - 1];
            a[i - 1] = a[i];
            a[i] = i + 1;
        }
        else {
            cout << "Too chaotic\n";
            return;
        }
    }

    cout << cnt << "\n";
}

///////////////////////////////////
// another way of doing this

const int maxn = 1e5 + 5;
int bit[maxn];

void update(int i, int val) {
    for (; i < maxn; i += i & -i) bit[i] += val;
}
int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

// Complete the minimumBribes function below.
void minimumBribes(vector<int> a) {

    int n = a.size();
    memset(bit, 0, sizeof(bit));

    bit[n - 1] = 0;
    update(a[n - 1], 1);

    int bribes = 0;
    for (int i = n - 2; i >= 0; --i) {
        int t = a[i] > 1 ? sum(a[i] - 1) : 0;
        if (t > 2) {
            cout << "Too chaotic\n";
            return;
        }
        bribes += t;
        update(a[i], 1);
    }
    cout << bribes << "\n";
}