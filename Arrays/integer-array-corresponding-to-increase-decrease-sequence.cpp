/*Given a string of size 'n' where each character can be either 'd' or 'i' and nothing else. If character 'd' denotes decrease 
in value and character 'i' denotes increase in value then how can we build an integer array of size 'n+1' created by using 
numbers from 1 to 'n+1' such that this array holds one to one correspondence with the input string.

For example, if the given string is "di" then because string size is 2, we need to use numbers 1,2,3 and build integer array [3,1,2] 
where first pair formed by first two elements 3,1 corresponds to character 'd' since there is decrease in value from 3 to 1 and 
then second pair 1,2 corresponds to character 'i' - increase in value from 1 to 2. Another way to build this could have been [2,1,3]. 
Now pair (2,1) corresponds to 'd' and second pair (1,3) corresponds to character 'i'.

When we consider 'n' such pairs formed out of adjacent elements from 'n+1' elements, 'n' pairs 
should correspond to 'n' characters of input string in the same sequence.

Another example could be for input string 'ddddi', one of the outputs could be [5,4,3,2,1,6] [6,4,3,2,1,5].

Write a program to create any one of the correct output integer array given an input string having characters 'd' and 'i'.

The idea is to use the higher numbers for satisfying 'i' transitions and remaining numbers for 'd' transitions.

Let's look at an example. Say we have a string consisting of only 2 'i's and 3 'd's - 'ddidi'
Then out of numbers 1,2,3,4,5,6 we reserve two higher numbers 6 and 5 for 'i' transitions because no matter what the current 
number we can always satisfy 'i' transitions using these higher numbers. The number next to reserved numbers for 'i' transitions 
is put at the 0th position. In this case, number next to 6 and 5 would be 4 hence we make output[0] = 4. Note that out of 1,2,3,4,5,6 
we have marked top 2 numbers that is 6 and 5 for 'i' transitions and next number to them that is 4 as a start value for output array - 
therefore remaining numbers(that is 3,2,1) would be used for 'd' transitions. Now we mark lowest number from the numbers 
reserved for 'i' transitions as increaseValue - in this case increaseValue would be 5. Similarly, we mark highest number from numbers 
that are going to used for 'd' transitions as decreaseValue - in this case decreaseValue would be 3.

Now the algorithm is very simple. Whenever we see a 'd' at string[i], we just put decreaseValue at output[i+1] and decrement 
decreaseValue by 1. And whenever we see a 'i' at string[i], we just put increaseValue at output[i+1] and increment increaseValue by 1. 
Output[0] is already initilaized to the number next to numbers reserved for 'i' and 'd' transitions.*/

int* Convert(string s) {

	int N = s.size();
	int *output = new int[N+1];

	int iCnt = 0;
	REP(i, 0, N) if(s[i] == 'i') iCnt++;

	int increaseValue = N+2 - iCnt;

	int decreaseValue = increaseValue - 2;

	output[0] = increaseValue - 1;

	REP(i, 0, N) {
		if(s[i] == 'd')
			output[i+1] = decreaseValue--;

		else if(s[i] == 'i') 
			output[i+1] = increaseValue++;
	}

	return output;
}