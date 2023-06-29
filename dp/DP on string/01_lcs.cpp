#incldue<bits/stdc++.h>
using namespace std;

class DP {
private:
    vector<vector<int>>dp;
public:
    DP(int n,int m){
        dp.resize(n+1,vector<int>(m+1,-1));
    }

    // memoization
    int lcsMemo(string &s,string &t,int n,int m){
        if(n<0 or m<0) 
            return 0;
        if(dp[n][m]!=-1) 
            return dp[n][m];
        if(s[n]==t[m])
            return dp[n][m] =  1 + lcsMemo(s,t,n-1,m-1);
        else    
        {
            int op1 = lcsMemo(s,t,n-1,m);
            int op2 = lcsMemo(s,t,n,m-1);
            return dp[n][m] = max(op1,op2);
        }
    }

    // tabulation
    int lcsTabu(string &s,string &t,int n,int m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
int main(){

    return 0;
}