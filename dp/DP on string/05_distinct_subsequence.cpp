class Solution {
public:
    const int N = 1e9+7;
    int f(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m] = f(s,t,n-1,m-1,dp) + f(s,t,n-1,m,dp);
        }
        else
            return dp[n][m] = f(s,t,n-1,m,dp);
    }
    int f2(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        dp[0][0] = 1;
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%N;
                else
                   a dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return f2(s,t,n,m,dp);
    }
};