/*Count Balanced Binary Trees of Height h
Given a height h, count and return the maximum number of balanced binary trees possible with height h. 
A balanced binary tree is one in which for every node, the difference between heights of left and right 
subtree is not more than 1.

Input : h = 3
Output : 15

Input : h = 4
Output : 315We can cleary see that the last level can have 2^(h-1) no of nodes. Each node can be present or not present 
in the tree. So the ans will be :
Let x = 2^(h-1);
ans = 2^(x) - 1;*/

/*We can cleary see that the last level can have 2^(h-1) no of nodes. 
Each node can be present or not present in the tree. So the ans will be :
Let x = 2^(h-1);
ans = 2^(x) - 1; 1 is subtracted because we need atleast one node in the last level*/