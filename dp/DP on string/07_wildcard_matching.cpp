class Solution {
public:
    bool f(string &s,string &p,int n,int m,vector<vector<int>>&dp){
        if(n<0){
            for(int l=m;l>=0;l--){
                if(p[l]!='*')
                    return false;
            }
            return true;
        }
        if(m<0) return false;
        if(dp[n][m]!=-1) return dp[n][m];
        if(p[m]=='?' or (s[n]==p[m]))
            return dp[n][m] = f(s,p,n-1,m-1,dp);
        else if(p[m]=='*'){
            return dp[n][m] = f(s,p,n,m-1,dp) | f(s,p,n-1,m,dp);
        }
        return dp[n][m] = false;
    }
    bool f2(string &s,string &p,int n,int m,vector<vector<int>>&dp){
        for(int i=1;i<=m;i++){
            if(p[i-1]!='*') break;
            dp[0][i] = true;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='?' or (s[i-1]==p[j-1]))
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return f2(s,p,n,m,dp);
    }
};