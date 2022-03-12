//  https://leetcode.com/problems/climbing-stairs/submissions/

class Solution {

public:
    
    int stairs(int n,int k,int* dp){
        if(n==0){
            dp[0] = 1;
            return 1;
        }
        if(n <0){
            // dp[n] = 0;
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int sum =0;
        // for(int i=1;i<=k;i++){
        //     sum += stairs(n-i,k,dp);
        // }
        sum = stairs(n-1,k,dp) + stairs(n-2,k,dp);
        dp[n] = sum;
        return sum;
    }
    
    int stairs2(int n,int k){
        int* dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        int ans = 0;
		for(int i=2;i<=n;i++){
            int ans =0;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                ans = ans + dp[i-j];
                }
                
            }
            dp[i] =ans; 
        }
        
        return dp[n];
    }    
    

    int stairs2(int n,int k){
        int* dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }    

    int climbStairs(int n) {
       int *dp = new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        return stairs2(n,2);
    }
};