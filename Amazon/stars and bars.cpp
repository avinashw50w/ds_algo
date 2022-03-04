public class Main {
    public static void main(String[] args) {
        String s = "|*||*";
        int i=0, n = s.length();
        while(i<n && s.charAt(i)!='|') i++;
        
        int[] dp = new int[n];
        int count = 0;
        i++;
        while(i<n){
            if(s.charAt(i)=='|'){
                dp[i] = dp[i-1] + count;
                count = 0;
            } else {
                dp[i] = dp[i-1];
                count++;
            }
            i++;
        }
        
        System.out.println("indexing from 0 hence 1 -> 5: " + (dp[4] - dp[0]));
        System.out.println("indexing from 0 hence 1 -> 6: " + (dp[5] - dp[0]));
    }
}