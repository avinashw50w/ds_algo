/*
Given two strings A and B, the task is to find the smallest substring of A having B as a subsequence. If there are multiple such substrings in A, return the substring that has the smallest starting index. 

Examples : 

Input : A = “abcedbaced” B = “bed”
Output : “bced”
Explanation : The substring A[2 : 5] is the shortest substring that contains the string ‘B’ as a subsequence.

Input : A = “abcdbad” B = “bd”
Output : “bcd”
Explanation : Although both the substrings A[2:4] and A[5:7] have the same length, the substring which has the smallest starting index is “bcd” so it is the final answer. 
 */

int dp[100][100];
 
// Function to find the smallest substring in string A which
// contains string B as a subsequence.
string smallestSubstring(string& A, string& B)
{
    // Size of string A
    int a = A.size();
 
    // Size of string B
    int b = B.size();
 
    // Initializing the first column of dp array.
    // Storing the occurence of first character of string B
    // in first (i + 1) characters of string A.
    for (int i = 0; i < a; ++i) {
 
        // If the current character of string A does not
        // match the first character of string B.
        if (i > 0 and A[i] != B[0]) {
            dp[i][0] = dp[i - 1][0];
        }
 
        // If the current character of string A is equal to
        // the first character of string B.
        if (A[i] == B[0]) {
            dp[i][0] = i;
        }
    }
 
    // Iterating through remaining characters of string B.
    for (int j = 1; j < b; ++j) {
 
        // Checking if any character in string A matches
        // with the current character of string B.
        for (int i = 1; i < a; ++i) {
 
            // If there is a match, then starting index of
            // required substring in string 'A' is equal to
            // the starting index when first 'j - 1'
            // characters of string 'B' matched with first
            // 'i - 1' characters of string 'A'.
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
 
            // Else, starting index of required substring in
            // string 'A' is equal to the starting index
            // when first 'j' characters of string 'B'
            // matched with first 'i - 1' characters of
            // string 'A'.
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
 
    // String for storing final answer
    string answer = "";
 
    // Length of smallest substring
    int best_length = 1e9;
 
    for (int i = 0; i < a; ++i) {
 
        // dp[i][b-1] is the index in string 'A', such that
        // the substring A(dp[i][b-1] : i) contains string
        // 'B' as a subsequence.
        if (dp[i][b - 1] != -1) {
 
            // Starting index of substring
            int start = dp[i][b - 1];
 
            // Ending index of substring
            int end = i;
 
            // Length of substring
            int current_length = end - start + 1;
 
            // if current length is lesser than the best
            // length update the answer.
            if (current_length < best_length) {
                best_length = current_length;
 
                // Update the answer
                answer = A.substr(start, best_length);
            }
        }
    }
 
    // Return the smallest substring
    return answer;
}
 
// This function is initializing dp with -1
// and printing the result
void smallestSubstringUtil(string& A, string& B)
{
    // Initialize dp array with -1
    memset(dp, -1, sizeof dp);
 
    // Function call
    cout << smallestSubstring(A, B) << endl;
}
 
// Driver code
int main()
{
    // Input strings
    string A = "abcedbaced";
    string B = "bed";
 
    // Function Call
    smallestSubstringUtil(A, B);
 
    return 0;
}

// Time Complexity: O(N2) 
// Auxiliary Space:  O(N2)

// another space optimised one
int minLength(string a, string b)
{
  
    // Stores the characters present
    // in string b
    map<char, int> Char;
    for (int i = 0; i < b.length(); i++) {
  
        Char[b[i]]++;
    }
  
    // Find index of characters of a
    // that are also present in string b
    map<char, vector<int> > CharacterIndex;
  
    for (int i = 0; i < a.length(); i++) {
  
        char x = a[i];
  
        // If character is present in string b
        if (Char.find(x) != Char.end()) {
  
            // Store the index of character
            CharacterIndex[x].push_back(i);
        }
    }
  
    int len = INT_MAX;
  
    // Flag is used to check if
    // substring is possible
    int flag;
  
    while (true) {
  
        // Assume that substring is
        // possible
        flag = 1;
  
        // Stores first and last
        // indices of the substring
        // respectively
        int firstVar, lastVar;
  
        for (int i = 0; i < b.length(); i++) {
  
            // For first character of string b
            if (i == 0) {
  
                // If the first character of
                // b is not present in a
                if (CharacterIndex.find(b[i])
                    == CharacterIndex.end()) {
  
                    flag = 0;
                    break;
                }
  
                // If the first character of b
                // is present in a
                else {
  
                    int x = *(
                        CharacterIndex[b[i]].begin());
  
                    // Remove the index from map
                    CharacterIndex[b[i]].erase(
                        CharacterIndex[b[i]].begin());
  
                    // Update indices of
                    // the substring
                    firstVar = x;
                    lastVar = x;
                }
            }
  
            // For the remaining characters of b
            else {
  
                int elementFound = 0;
                for (auto e : CharacterIndex[b[i]]) {
  
                    if (e > lastVar) {
  
                        // If index possible for
                        // current character
                        elementFound = 1;
                        lastVar = e;
                        break;
                    }
                }
                if (elementFound == 0) {
  
                    // If no index is possible
                    flag = 0;
                    break;
                }
            }
        }
  
        if (flag == 0) {
  
            // If no more substring
            // is possible
            break;
        }
  
        // Update the minimum length
        // of substring
        len = min(len,
                  abs(lastVar - firstVar) + 1);
    }
  
    // Return the result
    return len;
}