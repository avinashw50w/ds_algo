/*Print all the paths from root, with sum k in Binary tree
Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum.*/

void printpath(Node *root, int k, int sum, vector<int> path) {
    if (!root) return;

    sum += root->data;

    path.push_back(root->data);

    if (sum == k) print(path);

    printpath(root->left, k, sum, path);
    printpath(root->right, k, sum, path);

    // Remove last element from path
    // and move back to parent
    path.pop_back();
}