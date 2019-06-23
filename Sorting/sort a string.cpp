/*Given a string 
S
S, and two numbers 
N
N, 
M
M - arrange the characters of string in between the indexes 
N
N and 
M
M (both inclusive) in descending order. (Indexing starts from 0).

Input Format:
First line contains 
T
T - number of test cases.
Next T lines contains a string(
S
S) and two numbers(
N
N, 
M
M) separated by spaces.

Output Format:
Print the modified string for each test case in new line.

SAMPLE INPUT 
3
hlleo 1 3
ooneefspd 0 8
effort 1 4

SAMPLE OUTPUT 
hlleo
spoonfeed
erofft */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   string s; 
   int n, m;
   int t; cin>>t;
   while(t--) {
   	cin>>s;
   	cin>>n>>m;
   	sort(s.begin()+n, s.begin()+m+1, greater<char>());
   	cout <<s<<endl;
   }
}
