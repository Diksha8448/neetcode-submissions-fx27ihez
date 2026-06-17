class Solution {
public:
   int solve(int n,vector<int>&dp){
      // base case 
      if(n<=2){
        return n;
      }

      // store the value
      if(dp[n]!=-1){
          return dp[n];
      }

      return dp[n]=solve(n-1,dp)+solve(n-2,dp);
   }
    int climbStairs(int n) {
        // TLE
        // if(n<=2){
        //     return n;
        // }

        // return climbStairs(n-1)+climbStairs(n-2);
        // we are using memoization
        vector<int>dp(n+1,-1);
         return solve(n,dp);
    }
};
