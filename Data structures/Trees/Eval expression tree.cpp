/*Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input:
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100*/

int evalTree(node* root) {
	// Your code here
	if (!root) return 0;
	if (!root->left and !root->right) return stoi(root->data);
	int ls = evalTree(root->left);
	int rs = evalTree(root->right);

	if (root->data == "+") return ls + rs;
	if (root->data == "-") return ls - rs;
	if (root->data == "*") return ls * rs;
	if (root->data == "/") return ls / rs;
}