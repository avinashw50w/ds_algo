#include<iostream>
#include<map>
using namespace std;
struct node{
	int data;
	int rank;
	node* parent;
};

map<int,node*> Node;

void makeSet(int data){
	node* tmp=new node();
	tmp->data = data;
	tmp->rank = 0;
	tmp->parent = tmp;
	Node[data] = tmp;
}

node* findSet(node* n){          //   returns the parent of the set
	node* Parent = n->parent;
	if(Parent==n) return Parent;
	else return n->parent = findSet(n->parent);
}

void Union(int data1 , int data2){       //  it joins the two sets
    // get the nodes corresponding to each data.
	node* node1 = Node[data1];
	node* node2 = Node[data2];
	//  get the parents of these two nodes
	node* parent1 = findSet(node1);
	node* parent2 = findSet(node2);
	// if both these two nodes belong to the same set then do nothing and return
	if(parent1->data == parent2->data) return;
	
	// else whoever's rank is higher becomes the parent of other
	if(parent1->rank >= parent2->rank){
		// increment the rank of parent only if both their ranks are same
		parent1->rank = (parent1->rank==parent2->rank) ? parent1->rank+1 : parent1->rank;
		parent2->parent = parent1;      
	}
	else parent1->parent = parent2;
}

int main(){
	for(int i=1;i<8;i++)
		makeSet(i);
	Union(1,2);
	cout<<findSet(Node[1])->data<<" ";
	Union(2,3);
	cout<<findSet(Node[2])->data<<" ";
	Union(4,5);
	cout<<findSet(Node[4])->data<<" ";
	Union(6,7);
	cout<<findSet(Node[6])->data<<" ";
	Union(5,6);
	cout<<findSet(Node[5])->data<<" ";
	Union(3,7);
	cout<<findSet(Node[3])->data<<" ";
}
