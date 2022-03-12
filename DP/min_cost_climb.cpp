//  https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

class Solution {
public:
    
    int climb(vector<int>& cost,int* dp){
        dp[0] = cost[0];
        dp[1] = cost[1];
        int n = cost.size();
        for(int i=2;i<cost.size();i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        dp[n] = min(dp[n-1], dp[n-2]);
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int* dp = new int[2000];
        return climb(cost,dp);
    }
};