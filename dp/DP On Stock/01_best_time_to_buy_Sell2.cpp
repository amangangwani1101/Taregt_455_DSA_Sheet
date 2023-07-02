class Solution {
public:
    int f(vector<int>&prices,int idx,int op,vector<vector<int>>&dp){
        if(idx==prices.size()-1) return op?prices[idx]:0;
        if(dp[idx][op]!=-1) return dp[idx][op];
        if(!op){
            return dp[idx][op] = max(-prices[idx] + f(prices,idx+1,1-op,dp),f(prices,idx+1,op,dp));
        }
        return dp[idx][op] = max(prices[idx] + f(prices,idx+1,1-op,dp),f(prices,idx+1,op,dp));
    }

    int f2(vector<int>&prices,int n,int op,vector<vector<int>>&dp){
        dp[n-1][1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i][0] = max(-prices[i] + dp[i+1][1],dp[i+1][0]);
            dp[i][1] = max(prices[i] + dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        return f2(prices,n,0,dp);
    }
};