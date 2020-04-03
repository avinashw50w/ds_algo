/*Replace every element with the greatest element on right side
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. 
Since there is no element next to the last element, replace it with -1. For example, if the array is {16, 17, 4, 3, 5, 2}, 
then it should be modified to {17, 5, 5, 5, 2, -1}.

A tricky method is to replace all elements using one traversal of the array. The idea is to start from the rightmost element, 
move to the left side one by one, and keep track of the maximum element. Replace every element with the maximum element.*/

void nextGreatest(int arr[], int size)
{
  // Initialize the next greatest element 
  int max_from_right =  arr[size-1];
 
  arr[size-1] = -1;

  for(int i = size-2; i >= 0; i--) {

    int temp = arr[i];
    arr[i] = max_from_right;
 
    if(temp > max_from_right)
       max_from_right = temp;
  }
}
 
/*Output:
The modified array is:
17 5 5 5 2 -1
*/