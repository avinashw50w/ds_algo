
// level of root is 1 //
// using BFS
int findMax(node *root) {
	if(root == NULL) return 0;

	int ans = 0, cnt, max_cnt = 0, level = 1;

	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		cnt = q.size();
		if(cnt > max_cnt)
		{
			max_cnt = cnt;
			ans = level;
		}

		while(cnt--) {
			node *tmp = q.front();
			q.pop();
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
		
		level++;
	}
	
	return ans;
}


// using DFS
unordered_map<int, int> levelNodes; // levelNode[i] : the # of nodes at level i

void findMax(node *root, int level = 0) {
	if (!root) return;
	levelNodes[level]++;

	findMax(root->left, level + 1);
	findMax(root->right, level + 1);
}