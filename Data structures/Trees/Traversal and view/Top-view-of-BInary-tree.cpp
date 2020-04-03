/*       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6*/
void topView(Node *root) {

	int hd = 0;

	set<int> st;

	queue<pair<Node*, int> > q;

	q.push(make_pair(root, 0));

	while(!q.empty()) {

		auto top = q.front();

		hd = top.second;

		Node *tmp = top.first;

		if(st.count(hd) == 0) {
			st.insert(hd);
			cout << tmp->data << " ";
		}

		if(tmp->left) q.push(make_pair(tmp->left, hd-1));
		if(tmp->right) q.push(make_pair(tmp->right, hd+1));
	}
}
