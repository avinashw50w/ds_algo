class Solution {
    
    long long sum(vector<int> a, bool isMin){
        const int n = a.size();
        if (!isMin){
            for (int i = 0; i < n; i++){
                a[i] *= -1;
            }
        }
        vector<int> left(n, 0), right(n, n-1);
        vector<int> st;
        for (int i = 0; i < n; i++){
            int curr = a[i];
            while (!st.empty() && curr < a[st.back()]){
                right[st.back()] = i-1;
                st.pop_back();
            }
            if (!st.empty())
                left[i] = st.back()+1;
            st.push_back(i);
        }      
              
        long long ans = 0;
        for (int i = 0; i < n; i++){
            ans += (long long)a[i]*(i-left[i]+1) * (right[i]-i+1);
        }
        
        return (isMin ? ans : ans*(-1));
    }
public:
    long long subArrayRanges(vector<int>& a) {
        const int n = a.size();
        
        return sum(a, false) - sum(a, true);
    }
};