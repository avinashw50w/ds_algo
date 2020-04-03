
int height(node* root) {
	if(root == NULL) return 0;

	int height = 0;
	
	queue<node*> q;
	q.push(root);

	while(1) {

		int node_cnt = q.size();
		// if node count is zero, means there are no nodes in this level,
		// so simply return the height
		if(node_cnt == 0) return height;

		height++;
		// Dequeue all nodes of current level and Enqueue all
        // nodes of next level
		for (int i = 0; i < cnt; ++i) {
			node *tmp = q.front();
			q.pop();
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
	}
}