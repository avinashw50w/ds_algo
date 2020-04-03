
// level of root is 1 //
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
