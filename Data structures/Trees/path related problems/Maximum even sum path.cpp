/*Given a binary tree. Find the maximum even sum along any path*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int v) {
		val = v;
		left = right = NULL;
	}
};


struct Sums {
	int e;
	int o;
	Sums(int even, int odd) {
		e = even;
		o = odd;
	}
};

Sums MaxSums(Node *n, int &max_esum)
{
    Sums out(0, 0);
    if (n) {
        Sums l_max_sums = MaxSums(n->left, max_esum);
        Sums r_max_sums = MaxSums(n->right, max_esum);

        vector<int> sums = {
            l_max_sums.e + n->val,
            l_max_sums.o + n->val,
            r_max_sums.e + n->val,
            r_max_sums.o + n->val,
            l_max_sums.e + r_max_sums.e + n->val,
            l_max_sums.e + r_max_sums.o + n->val,
            l_max_sums.o + r_max_sums.e + n->val,
            l_max_sums.o + r_max_sums.o + n->val
        };

        for (int i = 0; i < 4; ++i) {
            int sum = sums[i];
            if (sum % 2 == 0) {
                out.e = max(out.e, sum);
                max_esum = max(max_esum, out.e);
            } else {
                out.o = max(out.o, sum);
            }
        }

        for (int i = 4; i < sums.size(); ++i) {
            int sum = sums[i];
            if (sum % 2 == 0) {
				max_esum = max(max_esum, sum);
            }
        }
    }

	return out;
}

int main()
{
/*
      10
     /    \
    2      5
   /  \      \
  1   101    13
*/
    Node n10(10), n2(2), n5(5), n1(1), n101(101), n13(13);
    n10.left = &n2;
    n10.right = &n5;
    n2.left = &n1;
    n2.right = &n101;
    n5.right = &n13;

    int max_esum = 0;
    MaxSums(&n10, max_esum);
    cout << max_esum << "\n";
}