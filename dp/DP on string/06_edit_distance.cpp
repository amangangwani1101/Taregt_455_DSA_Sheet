class Solution {
  public:
    int f(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        if(n<0)
            return m+1;
        if(m<0)
            return n+1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]) 
            return dp[n][m] = f(s,t,n-1,m-1,dp);
        else{
            int op1 = 1 + f(s,t,n,m-1,dp);
            int op2 = 1 + f(s,t,n-1,m,dp);
            int op3 = 1 + f(s,t,n-1,m-1,dp);
            return dp[n][m] = min({op1,op2,op3});
        }
    }
    int f2(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        for(int i=0;i<=m;i++)
            dp[0][i] = i;
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               if(s[i-1]==t[j-1]) 
                   dp[i][j] = dp[i-1][j-1];
                else{
                    int op1 = 1 + dp[i][j-1];
                    int op2 = 1 + dp[i-1][j];
                    int op3 = 1 + dp[i-1][j-1];
                    dp[i][j] = min({op1,op2,op3});
                } 
            }
        }
        return dp[n][m];
    }
    
    int editDistance(string s, string t) {
        // Code here
        int n = s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return f2(s,t,n,m,dp);
    }
};
