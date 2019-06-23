/*Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    }     
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.*/

class Solution {
    public:
        vector<string> prettyJSON(string json) {
            vector<string> ans;
            if (json.length() == 0) return ans;
            // remove all spaces. 
            json.erase(remove(json.begin(), json.end(), ' '), json.end());

            string indent = "";
            string current = "";
            int i = 0, len = json.length();
            while (i < len) {
                current.push_back(json[i]);
                switch(json[i]) {
                    case ',':
                        ans.push_back(current);
                        current = indent;
                        i++;
                        break;
                    case ':':
                        i++;
                        if (json[i] == '{' || json[i] == '[') {
                            ans.push_back(current);
                            current = indent;
                        }
                        break;
                    case '{':
                    case '[':
                        i++;
                        ans.push_back(current);
                        if (i < len && (json[i] != '}' || json[i] != ']')) {
                            indent.push_back('\t');
                        }
                        current = indent;
                        break;
                    case '}':
                    case ']':
                        i++;
                        if (i < len && json[i] == ',') break;
                        ans.push_back(current);
                        if (i < len && (json[i] == '}' || json[i] == ']')) {
                            if (!indent.empty()) indent.pop_back();
                        }
                        current = indent;
                        break;
                    default : 
                        i++;
                        if (i < len && (json[i] == '}' || json[i] == ']')) {
                            ans.push_back(current);
                            if (!indent.empty()) indent.pop_back();
                            current = indent;
                        }
                }
            }
            return ans;
        }
};

/////////////////////////////////////////////////////////////////////////////
// Fastest

vector<string> Solution::prettyJSON(string A) {
    vector<string> res;
    int ct = 0;
    for(int i = 0; i < A.size(); ){
        string line = string(ct, '\t');
        while(i < A.size() && A[i] == ' ')
            i++;
            
        if(A[i] == '[' || A[i] == '{'){
            res.push_back(line + A[i]);
            ct += 1;
            i++;
            continue;
        }
        
        if(A[i] == ']' || A[i] == '}'){
            ct -= 1;
            line = string(ct, '\t') + A[i];
            if(A[i + 1] == ',')
                line += A[++i];
            res.push_back(line);
            i++;
            continue;
        }
            
        while(i < A.size() && (A[i] != ',' && A[i] != '[' && A[i] != ']' && A[i] != '{' && A[i] != '}'))
            line += A[i++];
        if(i < A.size() && A[i] == ',')
            line += A[i++];
        res.push_back(line);
    }
    
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

vector<string> prettyJSON(string A)
{
    vector<string> res;
    int ct = 0, i = 0;

    while(i < A.size()) {
        while(i < A.size() and A[i] == ' ') i++;

        string line = string(ct, '\t');

        if(A[i] == '[' or A[i] == '{') {
            res.push_back(line + A[i]);
            ct++, i++;
            continue;
        } 

        if(A[i] == ']' or A[i] == '}') {
            ct -= 1;
            line = string(ct, '\t') + A[i];

            if(A[i+1] == ',') line += A[i];
            res.push_back(line);
            i++;
            continue;
        }

        while(i < A.size() and A[i] != ',' and A[i] != '[' and A[i] != ']' and A[i] != '{' and A[i] != '}') line += A[i++];

        if(i < A.size() and A[i] == ',') line += A[i++];

        res.push_back(line);
    }

    return res;

}

int main() {
    string s;
    cin>>s;

    vector<string> ans = prettyJSON(s);

    for(auto i : ans) cout << i << endl;
}