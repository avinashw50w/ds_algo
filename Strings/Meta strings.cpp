/*Meta Strings (Check if two strings can become same after a swap in one string)
Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

Examples:

Input : str1 = "geeks" 
        str2 = "keegs"
Output : Yes
By just swapping 'k' and 'g' in any of string, 
both will become same.
*/


bool solve(string a, string b) {

	int prev = -1, curr = -1;
	int cnt = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			cnt++;

			if (cnt > 2) return false;

			prev = curr;
			curr = i;
		}
	}

	return (cnt == 2 and a[curr] == b[prev] and a[prev] == b[curr]);
}

int main() 
{ 
    string str1 = "converse"; 
    string str2 = "conserve"; 
  
    areMetaStrings(str1,str2) ? cout << "Yes"
                            : cout << "No"; 
    return 0; 
} 