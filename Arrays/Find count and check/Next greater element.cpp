void printNGE(int arr[], int n)
{
    int i = 0;
    stack<int> s;
    int top, next;
 
    /* push the first element to stack */
    s.push(arr[0]);
 
    // iterate for rest of the elements
    for (i=1; i<n; i++)
    {
        next = arr[i];
 
        if (!s.empty())
        {
            // if stack is not empty, then pop an element from stack
            top = s.top(); s.pop();
 
            /* If the popped element is smaller than next, then
                a) print the pair
                b) keep popping while elements are smaller and
                stack is not empty */
            while (top < next)
            {
                printf("\n %d --> %d", top, next);
                if(s.empty())
                   break;
                top = s.top(); s.pop();
            }
 
            /* If element is greater than next, then push
               the element back */
            if (top > next)
                s.push(top);
        }
 
        /* push next to stack so that we can find
           next greater for it */
        s.push(next);
    }
 
    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (!s.empty())
    {
        top = s.top(); s.pop();
        next = -1;
        printf("\n %d -- %d", top, next);
    }
}

/*Method 2 (Using Stack)
Thanks to pchild for suggesting following approach.
1) Push the first element to stack.
2) Pick rest of the elements one by one and follow following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
….g) If next is smaller than the popped element, then push the popped element back.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.
*/
