/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}


//////////////////////////////////////////////////////
struct Node {
  int data;
  Node *next;
};

class Solution {
  Node *head;
public:
  Solution(): head(NULL) {}

  Node *getHead() {
    return this->head;
  }

  Node* newNode(int val) {
    Node *tmp = new Node;
    tmp->next = NULL;
    tmp->data = val;
    return tmp;
  }

  void insert(int val) {
    Node *tmp = newNode(val);
    tmp->next = head;
    head = tmp;
  }

  void print() {
    Node *curr = head;
    while(curr) cout << curr->data << " ", curr = curr->next;
    cout << endl;
  }
  
  void swapNodes(int a, int b) {
    
    Node *curr1 = head, *prev1 = NULL;
    while(curr1 and curr1->data != a) {
      prev1 = curr1;
      curr1 = curr1->next;
    }

    Node *curr2 = head, *prev2 = NULL;
    while(curr2 and curr2->data != b) {
      prev2 = curr2;
      curr2 = curr2->next;
    }

    if (!curr1 or !curr2) return;

    if (prev1 != NULL) {
      prev1->next = curr2;
    } else {
      head = curr2;
    }

    if (prev2) {
      prev2->next = curr1;
    } else {
      head = curr1;
    }

    Node *tmp = curr2->next; 
    curr2->next = curr1->next;
    curr1->next = tmp;
  } 


};

int main() {
  Solution s;
  s.insert(5);
  s.insert(4);
  s.insert(3);
  s.insert(2);
  s.insert(1);
  s.swapNodes(2, 4);
  s.print();
}

/*
A->B->C->D->E
A->D->C->B->E

prev1 = A
prev2 = C
curr1 = B
curr2 = D

prev1->next = curr2
prev2->next = curr1
tmp = curr2->next;
curr2->next = curr1->next;
curr1->next = tmp;

 */