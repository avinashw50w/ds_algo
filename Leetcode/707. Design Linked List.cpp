/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of 
the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate 
the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. 
After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the
 linked list. If index equals the length of the linked list, the node will be appended to the 
 end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.*/
class MyLinkedList {
    struct Node {
        int val;
        Node *next;
        Node(int val) {
            this->val = val;
            next = NULL;
        }
    };
    Node *head, *tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *curr = head;
        for (int i = 0; i < index and curr; ++i) {
            curr = curr->next;
        }
        
        return curr ? curr->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val);
        if (!head) head = tail = node;
        else {
            node->next = head;
            head = node;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *node = new Node(val);
        if (!head) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }
    
    void print() {
        cout << "head" << endl;
        Node *curr = head;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node *node = new Node(val);
        Node *curr = head;
        for (int i = 0; i < index - 1 and curr; ++i) {
            curr = curr->next;
        }
        
        if (curr) {
            Node *next = curr->next;
            if (next == NULL) {
                tail->next = node;
                tail = node;
            }
            else {
                node->next = next;
                curr->next = node;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
        }
        Node *curr = head;
        for (int i = 0; i < index-1 and curr; ++i) {
            curr = curr->next;
        }
        
        if (curr and curr->next) {
            if (curr->next->next == NULL) tail = curr;
            curr->next = curr->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */