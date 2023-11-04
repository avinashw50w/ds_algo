/*A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation: 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.*/

class Solution {
    
    vector<string> parse(string s) {
        stringstream ss(s);
        vector<string> a;
        vector<string> res;
        while(ss) {
            string tmp;
            ss >> tmp;
            a.push_back(tmp);
        }
        
        res.push_back(a[0]);
        int len = a[1].size();
        
        for (int i = len-1; i >= 0; --i) {
            if (a[1][i] == '.') res.push_back(a[1].substr(i+1, len-1-i));
        }
        
        res.push_back(a[1]);
        
        return res;
    }
public:
    vector<string> subdomainVisits(vector<string>& domains) {
        int N = domains.size();
        map<string,int> mp;
        
        for (int i = 0; i < N; ++i) {
            vector<string> parts = parse(domains[i]);
            
            for (int j = 1; j < parts.size(); j++) {
                if (mp.count(parts[j])) mp[parts[j]] += stoi(parts[0]);
                else mp[parts[j]] = stoi(parts[0]);
            }
        }
        
        vector<string> res;
        for (auto s: mp) {
            string str = to_string(s.second) + " " + s.first;
            res.push_back(str);
        }
        
        return res;
    }
};