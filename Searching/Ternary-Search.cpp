/*Ternary Search as the name suggests, we divide the array in
3
3 parts and then look for the element in each part.

Similarly like binary search, ternary search is the divide and conquer algorithm and for it the array should be sorted in
which we are looking for the element. In this search, after each iteration it neglects the 1/3 part of the array and repeats
the same operations on the remaining 2/3 part of the array.*/

int ternary_search(int l, int r, int x)
{
  if (l <= r) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r -  (r - l) / 3;
    if (ar[mid1] == x)
      return mid1;
    if (ar[mid2] == x)
      return mid2;
    if (x < ar[mid1])
      return ternary_search(l, mid1 - 1, x);
    else if (x > ar[mid2])
      return ternary_search(mid2 + 1, r, x);
    else
      return ternary_search(mid1 + 1, mid2 - 1, x);

  }
  return -1;
}

/*Use of Ternary Search:

This concept is basically used in unimodal functions, to determine the maximum or minimum value of that function. Unimodal functions are the ones,
having single highest value.

Let’s take a function func in the interval [a,b], and we need to find the x for which func(x) is maximized. The function func is unimodal in nature,
i.e it is strictly increasing in the interval [a,x] and strictly decreasing in the interval [x,b].

This can be done by various other methods like with the basic knowledge of differentiation or by using modified binary search.
In the case when the function is not easily differentiable, Ternary Search is quite useful. It is less prone to errors and easy
to implement when dealing with floating point integers and when the required maximum value is reached at the end of the interval.*/

Implementation:

double func(double x)
{
  return -1 * 1 * x * x + 2 * x + 3;
}


double ts(double start, double end)
{
  double l = start, r = end;

  for (int i = 0; i < 200; i++) {
    double l1 = (l * 2 + r) / 3;
    double l2 = (l + 2 * r) / 3;

    if (func(l1) > func(l2)) r = l2; else l = l1;
  }

  double x = l;
  return func(x);
}
/*
Here the code is doing 200 iterations because at each step the interval [a,b] is getting reduced to 2/3 of its previous size.
After 200 steps, the answer comes with an error of at most ⅔200 of the original interval, that is quite good precision. You can change it according to your need.

Let’s try to understand the code.First we are dividing the code in 3 parts, that are (starttol1),(l1+1tol2−1) and (l2,end)
and then at each iteration we are checking in which part the maximum lies and at last ignoring the ⅓ part of the current interval.
If fun(l1)>func(l2), then we can observe that the maximum value does not lie in the last interval, so we ignore it by assigning r=l2,
otherwise the maximum value does not lie in the first part.Taking a unimodal function, −ax2+bx+3 and taking a=1,b=2andc=3 as constants,
the maximum value of func(x) between the interval start=0 and end=1 will be 4.*/