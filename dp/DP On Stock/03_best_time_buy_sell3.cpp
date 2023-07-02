class Solution {
public:
    int f(vector<int>&price,int idx,int op,int cap,vector<vector<vector<int>>>&dp){
        if(idx==price.size() or !cap) 
            return 0;
        if(dp[idx][op][cap]!=-1)
            return dp[idx][op][cap];
        if(!op)
            return dp[idx][op][cap] = max(-price[idx] + f(price,idx+1,1-op,cap,dp),f(price,idx+1,op,cap,dp));
        else
            return dp[idx][op][cap] = max(price[idx] + f(price,idx+1,1-op,cap-1,dp),f(price,idx+1,op,cap,dp));
    }

    int f2(vector<int>&price,int n,int op,int cap,vector<vector<vector<int>>>&dp){
        for(int i=n-1;i>=0;i--){
            for(int c=1;c<=cap;c++){
                dp[i][0][c] = max(-price[i] + dp[i+1][1][c],dp[i+1][0][c]);
                dp[i][1][c] = max(price[i] + dp[i+1][0][c-1],dp[i+1][1][c]);
            }
        }
        return dp[0][0][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        return f2(prices,n,0,k,dp);
    }
};