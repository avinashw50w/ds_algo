/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
	int level = 1, odd_sum = 0, even_sum = 0;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()) {
		int cnt = q.size();
		while(cnt--) {
			Node *tmp = q.front();
			q.pop();
			if(level&1) odd_sum += tmp->data;
			else even_sum += tmp->data;

			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
		level++;
	}
	return odd_sum - even_sum;
}


