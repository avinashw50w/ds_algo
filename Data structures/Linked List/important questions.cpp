// binary tree to linked list
void solve(Node *root, Node *&head) {
    if (!root) return;

    solve(root->right, head);
    root->right = head;
    if (head) head->left = root;
    head = root;
    solve(root->left, head);
}
// check if the list is circular
bool checkCircular(Node *head) {
    Node *curr = root;
    while (curr and curr != head) curr = curr->next;
    return curr == head;
}
// find the middle of the linked list
Node *middle(Node *head) {
    if (!head) return NULL;
    Node *s = head, *f = head->next;
    while (f and f->next) {
        if (s == f) return s;
        s = s->next;
        f = f->next->next;
    }

    return NULL;
}
// check if two node values sums to x in a sorted linked list
bool pairSumInDLL(Node *head, int x) {
    Node *l = head, *r = head;
    while (r->next) r = r->next;

    while (l != r and l != r->next) {
        if (l->key + r->key == x) return true;
        if (l->key + r->key < x) l = l->next;
        else r = r->prev;
    }
}
// check linked list is palindrome or not
bool solve(Node *&left, Node *right) {
    if (right == NULL) return true;
    solve(left, right->next);
    bool ch = left->key == right->key;
    left = left->next;
    return ch;
}
bool checkListPalindrome(Node *head) {
    return solve(head, head);
}
// clone a linked list having random pointers
Node *clone(Node *head) {
    Node *curr = head, *copy = NULL;
    map<Node*, Node*> mp;

    while (curr) {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        copy = mp[curr];
        copy->next = mp[curr->next];
        copy->random = mp[curr->random];
        curr = curr->next;
    }

    return copy;
}
// convert a list to complete binary tree
Node *convertListToCompleteBinaryTree(Node *head) {
    Node *root = NULL;
    if (!head) return root;
    root = new Node(head->data);
    queue<Node*> q;
    q.push(root);
    head = head->next;

    while (head) {
        Node *top = q.front(); q.pop();
        Node *left = NULL, *right = NULL;

        left = new Node(head->data);
        head = head->next;
        q.push(left);
        if (head) {
            right = new Node(head->data);
            head = head->next;
            q.push(right);
        }

        top->left = left;
        top->right = right;
    }

    return root;
}

// delete a node if its position is given
void delete(Node *&head, int pos) {
    if (pos == 0) {
        delete head;
        return;
    }
    Node *curr = head;
    for (int i = 0; i < pos - 1 and curr; ++i) {
        curr = curr->next;
    }

    if (curr or curr->next) return;
    // the node to delete is curr->next
    Node *next = curr->next;

    curr->next = curr->next->next;
    delete next;
}

// delete N nodes after M nodes
void deleteNafterM(Node *&head, int N, int M) {
    Node *curr = head;
    while (curr) {
        // traverse M-1 nodes
        for (int i = 0; i < M - 1; ++i)
            curr = curr->next;

        if (!curr) return;
        Node *t = curr->next;
        for (int i = 0; i < N; ++i) {
            Node *tmp = t;
            t = t->next;
            delete tmp;
        }

        curr->next = t;
        curr = t;
    }
}

// reverse a linked list (iterative)
void reverse(Node *&head) {
    Node *curr = head, *prev = NULL;
    while (curr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->next;
    }
    head = prev;
}
// reverse a linked list (recursive)
void solve(Node *prev, Node *curr, Node *&head) {
    if (!curr->next) {
        curr->next = prev;
        head = curr;
        return;
    }

    Node *next = curr->next;
    curr->next = prev;
    solve(curr, next, head);
}
void reverse(Node *head) {
    solve(NULL, head, head);
}

// reverse a doubly linked list
void reverse(Node *&head) {
    Node *curr = head, *prev = NULL;
    while (curr) {
        Node *next = curr->next;
        curr->prev = next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
}

// sorted linked list to balanced bst
Tnode *solve(Node *&head, int n) {
    if (n <= 0) return NULL;

    Tnode *left = solve(head, n / 2);
    Tnode *root = new Node(head->data);
    root->left = left;

    head = head->next;
    root->right = solve(head, n - n / 2 - 1);
    return root;
}

Tnode *listToBST(Lnode *head) {
    int n = countNodes(head);
    return solve(head, n);
}

// reverse list in groups of K
Node *reverse(Node *head, int K) {
    Node *curr = head, *prev = NULL;
    int cnt = 0;
    while (curr and cnt < K) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (next) {
        head->next = reverse(next, K);
    }

    return prev;
}

// swap nodes in a linked list if their values are given
void swap(Node *&head, int x, int y) {
    if (x == y) return;

    Node *prevx = NULL, currx = head;
    while (currx and currx->data != x)
        prevx = currx, currx = currx->next;

    Node *prevy = NULL, *curry = head;
    while (curry and curry->data != y)
        prevy = curry, curry = curry->next;

    if (!currx or !curry) return;

    if (!prevx) {
        head = currx;
    }
    else prevx->next = curry;

    if (!prevy) {
        head = curry;
    }
    else prevy->next = currx;

    Node *t = curry->next;
    curry->next = currx->next;
    currx->next = t;
}

// xor linked list

Node *XOR(Node *a, Node *b) {
    return (Node*)((uintptr_t)a ^ (uintptr_t)b);
}

void insert(Node *&head, int data) {
    Node *n = new Node();
    n->data = data;
    n->npx = head;
    if (head) head->npx = XOR(head->npx, n);
    head = n;
}

void print(Node *head) {
    Node *prev = NULL, *curr = head;

    while (curr) {
        cout << curr->data << " ";
        Node *next = XOR(curr->npx, prev);
        prev = curr;
        curr = next;
    }
}