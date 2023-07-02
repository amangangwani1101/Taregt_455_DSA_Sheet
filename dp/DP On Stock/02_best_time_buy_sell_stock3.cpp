class Solution {
public:
    int f(vector<int>&prices,int idx,int op,vector<vector<int>>&dp){
        if(op==4 or idx==prices.size()) return 0;
        if(dp[idx][op]!=-1) return dp[idx][op];
        if((op%2)==0){
            return dp[idx][op] = max(-prices[idx] + f(prices,idx+1,op+1,dp),f(prices,idx+1,op,dp));
        }
        else{
            return dp[idx][op] = max(prices[idx] + f(prices,idx+1,op+1,dp),f(prices,idx+1,op,dp));
        }
    }

    int f2(vector<int>&prices,int n,int op,vector<vector<int>>&dp){
        dp[n-1][3] = dp[n-1][1] = prices[n-1]; 
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<4;j++){
                if((j%2)==0){
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1],dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] + dp[i+1][j+1],dp[i+1][j]);
                }        
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(5,0));
        return f2(prices,n,0,dp);
    }
};