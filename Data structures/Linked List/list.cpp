#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

node *root = NULL;

node* newNode(int val){
    node* tmp = new node;
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

void insert(int val){
    if(root == NULL){
        root = newNode(val);
        return;
    }
    node* curr = root;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode(val);
}

bool find(int val){
    if(root == NULL) return false;
    node* curr = root;
    while(curr != NULL){
        if(curr->data == val) 
            return true;
        curr = curr->next;
    }
    return false;
}

void erase(int val){
    if(root == NULL) return;
    node *tmp, *curr = root;
    if(root->data == val){
        tmp = root;
        root = root->next;
        delete tmp;
        return;
    }
  
    while(curr != NULL){
        if(curr->data == val) break;
    
        curr = curr->next;
    }
    if(curr == NULL)
    	throw string("list does not contain the val.");
    	
    else if(curr->next == NULL){
        delete curr;
    }
    else curr->next = curr->next->next;
}

void display(){
    node* curr = root;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
int main() {
    try{
        insert(1);
        insert(2);
        insert(3);

        erase(4);
        display();
    }
    catch(const string &s){
        cout << s << endl;
    }

    return 0;
}
