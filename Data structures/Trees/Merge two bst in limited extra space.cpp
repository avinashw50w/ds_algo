/*Merge two BSTs with limited extra space
Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form. The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number of nodes in second tree. Maximum allowed auxiliary space is O(height of the first tree + height of the second tree).

Examples:

First BST
       3
    /     \
   1       5
Second BST
    4
  /   \
2       6
Output: 1 2 3 4 5 6
*/
// do a single iterative inorder traversal for both the bst's and maintain
// a flag to check from which tree the last element was taken
// this is a simple merge technique used to merge two sorted arrays

void merge(Node *root1, Node *root2) {
    stack<int> s1, s2;
    bool first = true, second = true;
    Node *curr1 = root1, *curr2 = root2;
    vector<int> ans;

    while (curr1 or curr2 or !s1.empty() or !s2.empty()) {
        while (curr1 and first) {
            s1.push(curr1);
            curr1 = curr1->left;
        }
        while (curr2 and second) {
            s2.push(curr2);
            curr2 = curr2->left;
        }
        // reached extreme left of first tree, then get that val
        if (!curr1 and !s1.empty()) {
            curr1 = s1.top(); s1.pop();
        }
        // if reached an extreme left of second tree, then get its val in curr2
        if (!curr2 and !s2.empty()) {
            curr2 = s2.top(); s2.pop();
        }

        if (curr1 and curr2) {
            if (curr1->data < curr2->data) {
                ans.push_back(curr1->data);
                first = true;
                second = false;
                curr1 = curr1->right;
            }
            else if (curr2->data < curr1->data) {
                ans.push_back(curr2->data);
                first = false;
                second = true;
                curr2 = curr2->right;
            }
            else {
                ans.push_back(curr1->data);
                ans.push_back(curr2->data);
                first = true;
                second = true;
                curr1 = curr1->right;
                curr2 = curr2->right;
            }
        }
        else if (curr1) {
            ans.push_back(curr1);
            first = true;
            second = false;
            curr1 = curr1->right;
        }
        else if (curr2) {
            ans.push_back(curr2);
            first = false;
            second = true;
            curr2 = curr2->right;
        }
    }

    return ans;
}
////////////////////////////////////////////////////////////////

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void merge(Node *root1, Node *root2) {
    if (!root1) {
        inorder(root2);
        return;
    }

    if (!root2) {
        inorder(root1);
        return;
    }

    stack<Node*> s1, s2;
    Node *curr1 = root1, *curr2 = root2;

    while (curr1 or curr2 or s1.size() or s2.size()) {
        if (curr1 or curr2) {
            if (curr1) {
                s1.push(curr1->left);
                curr1 = curr1->left;
            }

            if (curr2) {
                s2.push(curr2->left);
                curr2 = curr2->left;
            }
        }
        else {

            if (s1.empty()) {
                if (!s2.empty()) {
                    curr2 = s2.top();
                    s2.pop();
                    curr2->left = NULL;
                    inorder(curr2);
                }

                return;
            }

            if (s2.empty()) {
                if (!s1.empty()) {
                    curr1 = s1.top(); s1.pop();
                    curr1->left = NULL;
                    inorder(curr1);
                    return;
                }
            }

            curr1 = s1.top();
            curr2 = s2.top();

            if (curr1->data < curr2->data) {
                cout << curr1->data << " ";
                curr1 = curr1->right;
                s1.pop();
                curr2 = NULL;
            }
            else {
                cout << curr2->data << " ";
                curr2 = curr2->right;
                s2.pop();
                curr1 = NULL;
            }
        }
    }
}