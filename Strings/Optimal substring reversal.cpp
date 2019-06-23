/*You are given a string S. Each character of S is either ‘a’, or ‘b’. You wish to 
reverse exactly one sub-string of S such that the new string is lexicographically 
smaller than all the other strings that you can get by reversing exactly 
one sub-string.
For example, given ‘abab’, you may choose to reverse the substring ‘ab’ that 
starts from index 2 (0-based). This gives you the string ‘abba’. But, if you 
choose the reverse the substring ‘ba’ starting from index 1, you will get ‘aabb’.
 There is no way of getting a smaller string, hence reversing the substring in the
 range [1, 2] is optimal.

Input:
First line contains a number T, the number of test cases.
Each test case contains a single string S. The characters of the string will be
 from the set { a, b }.

Output:
For each test case, print two numbers separated by comma; for example “x,y” 
(without the quotes and without any additional whitespace). “x,y” describe the 
starting index (0-based) and ending index respectively of the substring that must
 be reversed in order to acheive the smallest lexicographical string. If there are
 multiple possible answers, print the one with the smallest ‘x’. If there are still
 multiple answers possible, print the one with the smallest ‘y’.

Constraints:
1 ? T ? 100
1 ? length of S ? 1000

Sample Input:
5
abab
abba
bbaa
aaaa
babaabba

Sample Output:
1,2
1,3
0,3
0,0
0,4 */

void maxSwap(string s) {
	if(s.size() == 0)
  	return;
 //dynamic programming algorithm
 //This matrix records if the substring of s[j]....s[i] should be reversed or not
  
 	vector<vector<bool> > goodSwap(s.size(), vector<bool>(s.size(), false));
 	string minStr = s;//records the smallest string we can achieve
 	int start = 0;
 	int end = s.size() - 1;
  
  
 	for(int i = 0; i < s.size(); i++) {
  		for(int j = 0; j <= i; j++) {
    
   			bool good;
   			if(i - j < 2)
    			good = true;//if i == j or i = j + 1, always good to reverse
   			else {
    			if(s[j] == 'b' && s[i] == 'a')//always good to reverse
     				good = true;
    			else if (s[j] == 'a' && s[i] == 'b')//always bad to reverse
     				good = false;
    			else// if (s[i] == s[j]), depends on the reversability of s[j + 1]....s[i - 1] 
     				good = goodSwap[j + 1][i - 1];
   			}
   			
   			if(good = true){//if it is good to reverse
    			goodSwap[j][i] = true;
    			string newStr = s;
    			reverse(newStr.begin() + j, newStr.begin() + i + 1);//reverse the string
    			if(newStr <= minStr){//if the reversed string is smaller
     				start = j;
     				end = i;
     				minStr = newStr;//records the smallest string we can achieve
    			}
   			}
  		}
 	}
  
 	if(start==end)
    	cout<<"0"<<"  -  "<<"0"<<endl;
 	else
 		cout << start <<"  -  "<< end << endl;
}

int main()
{
 	maxSwap("abab");
 	maxSwap("abba");
 	maxSwap("bbaa"); 
 	maxSwap("aaaa"); 
 	maxSwap("babaabba"); 
 	return 0;
}