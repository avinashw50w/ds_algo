#include <iostream>
#include <string.h>
using namespace std;

string runLengthEncode(string str)
{
    int len = str.length();
    int j=0,k=0,cnt=0;
    for(int i=0;i<len;i++)
    {
        j=i;
        cnt=1;
        while(i<len-1 && str[i]==str[i+1])
        {
            i++;
            cnt++;
        }
        str[k++]=str[j];
        string temp =to_string(cnt);
        for(auto m:temp)
            str[k++] = m;
    }
    str.resize(k);
    return str;
}

/////////////////////////////////////////////////////////

/*You are required to complete this function */
char *encode(char *src)
{     
  int n = strlen(src);
  char *s = new char[2*n];
  int cnt, i, j, k = 0;
  
  for(i = 0; i < n; ++i) {
        cnt = 1;
        char c = src[i];
        while (i < n-1 and src[i] == src[i+1]) {
            i++;
            cnt++;
        }
        s[k++] = c;
        string x = to_string(cnt);
        for(auto m: x) s[k++] = m;
        
  }
  s[k] = '\0';
  return s;
}

 int main() {
   
    char c[] = "aaabbcccc";
    
    cout << encode(c);
 }
