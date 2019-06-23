/*Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 */

 int Solution::titleToNumber(string S) {
   
    int res = 0;
    
    for(int i = 0; i < S.length(); ++i)
        res = res*26 + (S[i]-'A'+1);
        
    return res;
}
