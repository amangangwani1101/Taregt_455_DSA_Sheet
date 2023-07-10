class Solution {
public:
    int f(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            mini = min(mini,cuts[j+1] - cuts[i-1] + f(cuts,i,k-1,dp) + f(cuts,k+1,j,dp));
        }
        return dp[i][j] = mini;
    }

    int f2(vector<int>&cuts,int n,vector<vector<int>>&dp){
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    mini = min(mini,cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n];
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        sort(cuts.begin(),cuts.end());
        return f2(cuts,m,dp);
    }
};