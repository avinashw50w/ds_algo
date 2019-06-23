/*Pairs involved in Balanced Parentheses
Given a string of brackets, task is to find the number of pairs of brackets involved in a balanced sequence in a given range.

Examples :

Input : ((())(()
Range : 1 5
Range : 3 8
Output : 2
         2
Explanation :  In range 1 to 5 ((()), 
there are the two pairs. In range 3 to 8 ())
((), there are the two pairs.

Input : )()()))
Range : 1 2
Range : 4 7
Output : 0
         1
Explanation :  In range 1 to 2 )( there 
is no any pair. In range 4 to 7 ())), 
there is the only pair

Here, in segment tree, for each node, keep some simple elements, like integers or sets or vectors or etc.
For each node keep three integers :
1. t = Answer for the interval.
2. o = The number of opening brackets ‘(‘ remaining after deleting the brackets 
those who belong to the correct bracket sequence in this interval whit length t.
3. c = The number of closing brackets ‘)’ remaining after deleting the brackets 
those who belong to the correct bracket sequence in this interval whit length t.
Now, having these variables, queries can be answered easily using segment tree.*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Our struct node 
struct node { 
      
    // three variables required 
    int t, o, c; 
}; 
  
// Declare array of nodes of very big 
// size which acts as segment tree here. 
struct node tree_arr[5 * 1000]; 
  
// To bulid a segment tree we pass 1 as 
// 'id' 0 as 'l' and l as 'n'. 
// Here, we consider query's interval as [x, y) 
void build(int id, int l, int r, string s) 
{ 
    /* this base condition is common to  
       build any segment tree*/
    // This is the base 
    // Only one element left 
    if (r - l < 2) { 
          
        // If that element is open bracket 
        if (s[l] == '(') 
            tree_arr[id].o = 1; 
          
        // If that element is open bracket 
        else
            tree_arr[id].c = 1; 
        return; 
    } 
  
    // Next three lines are common  
    // for any segment tree. 
    int mid = (l + r) / 2; 
      
    // for left tree 
    build(2 * id, l, mid, s);  
      
    // for right tree 
    build(2 * id + 1, mid, r, s); 
  
    // Here we take minimum of left tree 
    // opening brackets and right tree 
    // closing brackets 
    int tmp = min(tree_arr[2 * id].o, tree_arr[2 * id + 1].c); 
  
    // we add that to our answer. 
    tree_arr[id].t = tree_arr[2 * id].t + tree_arr[2 * id + 1].t + tmp; 
  
    // Remove the answer from opening brackets 
    tree_arr[id].o = tree_arr[2 * id].o + tree_arr[2 * id + 1].o - tmp; 
  
    // Remove the answer from opening brackets 
    tree_arr[id].c = tree_arr[2 * id].c + tree_arr[2 * id + 1].c - tmp; 
} 
  
// This will return the answer for each query. 
// Here we consider query's interval as [x, y) 
node segment(int x, int y, int id,  
             int l, int r, string s) 
{ 
    // If the given interval is out of range 
    if (l >= y || x >= r) { 
        struct node tem; 
        tem.t = 0; 
        tem.o = 0; 
        tem.c = 0; 
        return tem; 
    } 
  
    // If the given interval completely lies 
    if (x <= l && r <= y) 
        return tree_arr[id]; 
  
    // Next three lines are common for  
    // any segment tree. 
    int mid = (l + r) / 2; 
      
    // For left tree 
    struct node a = segment(x, y, 2 * id, l, mid, s); 
      
    // For right tree 
    struct node b = segment(x, y, 2 * id + 1, mid, r, s); 
  
    // Same as made in build function 
    int temp; 
    temp = min(a.o, b.c); 
    struct node vis; 
    vis.t = a.t + b.t + temp; 
    vis.o = a.o + b.o - temp; 
    vis.c = a.c + b.c - temp; 
  
    return vis; 
} 
  
// Driver code 
int main() 
{ 
    string s = "((())(()"; 
    int n = s.size(); 
  
    // range for query 
    int a = 3, b = 8; 
      
    build(1, 0, n, s); 
      
    // Here we consider query's interval as [a, b) 
    // We subtract 1 from 'a' because indexes start 
    // from 0. 
    struct node p = segment(a-1, b, 1, 0, n, s); 
    cout << p.t << endl; 
      
    return 0; 
} 