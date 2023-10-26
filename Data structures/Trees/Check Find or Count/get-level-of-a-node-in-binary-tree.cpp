
/* Helper function for getLevel().  It returns level of the data if data is
   present in tree, otherwise returns 0.*/
void getLevelUtil(struct node *node, int data, int &ans, int level = 1)
{
    if (node == NULL)
        return 0;
 
    if (node->data == data) {
        ans = level;
        return;
    }
 
    getLevelUtil(node->left, data, level+1);
    getLevelUtil(node->right, data, level+1);
}
 
/* Returns level of given data value */
int getLevel(struct node *node, int data)
{
    int ans = 0;
    getLevelUtil(node,data,ans);
    return ans;
}