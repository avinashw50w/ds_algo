/*Given a Binary Tree, we need to print the bottom view from left to right. A node x is there in output
if x is the bottommost node at its horizontal distance. Horizontal distance of left child of a node x is
equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.
For example, in the below diagram, 3 and 4 are both the bottom-most nodes at horizontal distance 0, we need to print 4.


                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \
                  10    14
For the above tree the output should be 5, 10, 4, 14, 25.
The following are steps to print Bottom View of Bianry Tree.
1. We put tree nodes in a queue for the level order traversal.
2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal
distance as hd-1 and right child as hd+1.
3. Also, use a TreeMap which stores key value pair sorted on key.
4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal
distance as key. For the first time it will add to the map, next time it will replace the value. This will make sure that
the bottom most element for that horizontal distance is present in the map and if you see the tree from beneath that you will see that element.*/

/* Tree node class */
struct Node
{
    int data;
    Node *left, *right;
};

// Method that prints the bottom view.
void bottomView(Node *root)
{
    if (root == NULL)
        return;

    // horizontal distance from root //
    int hd = 0;

    map<int, int> m;

    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        hd = top.second;
        Node *temp = top.first;

        m[hd] = temp->data;

        if (temp->left)
        {
            q.push(make_pair(temp->left, hd - 1));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }

    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";

}

///////////////////////////////////////////////////
// using only map


void bottomView(Node *root) {

    map<int, pair<int, int>> m; // m[d] = {a, b} , d = horizontal distance from root, a = root data, b = height from root

    solve(root, 0, 0, m);

    for (int i : m) {
        cout << i.first << " ";
    }
}

void solve(Node *root, int d, int height, map<int, pair<int, int>> m) {

    if (!root) return;

    if (m.count(d) == 0) m[d] = {root->data, height};
    else {

        auto p = m[d];
        if (p.second <= height) m[d] = {root->data, height};
    }

    solve(root->left, d - 1, height + 1, m);
    solve(root->right, d + 1, height + 1, m);
}
