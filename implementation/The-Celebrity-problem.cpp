/*The Celebrity Problem
In a party of N people, there may be a celebrity among them. Everyone knows the celebrity, but the celebrity doesn't know anyone.
Such a person may be present in the party, 
if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. 
Find the stranger (celebrity) in minimum number of questions.

We can describe the problem input as an array of numbers/characters representing persons in the party. 
We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. 

Method 3 (Using Stack)

The graph construction takes O(N2) time, it is similar to brute force search. In case of recursion, 
we reduce the problem instance by not more than one, and also combine step may examine M-1 persons (M – instance size).
We have following observation based on elimination technique (Refer Polya’s How to Solve It book).

If A knows B, then A can’t be celebrity. Discard A, and B may be celebrity.
If A doesn’t know B, then B can’t be celebrity. Discard B, and A may be celebrity.
Repeat above two steps till we left with only one person.
Ensure the remained person is celebrity. (Why do we need this step?)
We can use stack to verity celebrity.

Push all the celebrities into a stack.
Pop off top two persons from the stack, discard one person based on return status of HaveAcquaintance(A, B).
Push the remained person onto stack.
Repeat step 2 and 3 until only one person remains in the stack.
Check the remained person in stack doesn’t have acquaintance with anyone else.
We will discard N elements utmost (Why?). If the celebrity is present in the party, 
we will call HaveAcquaintance() 3(N-1) times. Here is code using stack.*/

// Max # of persons in the party
#define N 8
 
// Person with 2 is celebrity
bool  MATRIX[N][N] = {{0, 0, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 1, 0}};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
 
// Returns -1 if celebrity is not present.
// If present, returns id  (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial case of size = 2
 
    stack<int> s;
 
    int C; // Celebrity
 
    // Push everybody to stack
    for (int i=0; i<n; i++)
        s.push(i);
 
    // Extract top 2
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();
 
    // Find a potential celebrity
    while (s.size() > 1)
    {
        if (knows(A, B))	// if A knows B, then A can't be the celebrity
        {
            A = s.top();	// get the next element from stack
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }
 
    // Potential candidate?
    C = s.top();
    s.pop();
 // if C knows B, then C can't be the celebrity. So change C to B and check B
    if (knows(C, B))
        C = B;
 
    if (knows(C, A))
        C = A;
 
    // Check if C is actually a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If 'a' knows someone or someone doesn't 
        // know 'a', return -1
        if ( (i != C) && (knows(C, i) || !knows(i, C)) )
            return -1;
    }
 
    return C;
}
 
// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}

/*Complexity O(N). Total comparisons 3(N-1).*/

/*Method 4 (Using two Pointers)

The idea is to use two pointers, one from start and one from the end. Assume the start person is A, 
and the end person is B. If A knows B, then A must not be the celebrity. Else, B must not be the celebrity. 
We will find a celebrity candidate at the end of the loop.*/

bool knows(int a, int b) { return MATRIX[a][b]; }
 
// Returns id of celebrity
int findCelebrity(int n)
{
    int a = 0;
    int b = n - 1;
 
    while (a < b)
    {
        if (knows(a, b))
            a++;
        else
            b--;
    }
 
    // Check if a is actually a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If 'a' knows someone or someone doesn't 
        // know 'a', return -1
        if ( (i != a) && (knows(a, i) || !knows(i, a)) )
            return -1;
    }
 
    return a;
}