class Solution {
public:
    int f(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>j) 
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)    
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j] = 2 + f(s,i+1,j-1,dp);
        return dp[i][j] = max(f(s,i+1,j,dp),f(s,i,j-1,dp));
    }
    int f2(string &s,int n,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            int l=0,r = i;
            while(r<n){
                if(l==r) dp[l][r] = 1;
                else if(s[l]==s[r])
                    dp[l][r] = 2 + dp[l+1][r-1];
                else
                    dp[l][r] = max(dp[l+1][r],dp[l][r-1]);
                l++;
                r++;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return n - f2(s,n,dp);
    }
};