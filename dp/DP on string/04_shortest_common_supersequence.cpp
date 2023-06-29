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
    string lcsTabu(string &s,string &t,int n,int m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return lcsString(s,t,n,m);
    }

    string lcsString(string &s,string &t,int n,int m){
        n-=1;m-=1;
        string ans="";
        while(n>=0 and m>=0){
            if(s[n]==t[m]){
                ans+=s[n];
                n-=1;m-=1;
            }
            else if(dp[n+1][m+1]==dp[n+1][m])
                m-=1;
            else
                n-=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(),m = str2.size();
        DP soln(n,m);
        string lcs = soln.lcsTabu(str1,str2,n,m);
        int i,j,k;
        string ans="";
        for(i=0,j=0,k=0;i<n and j<m and k<lcs.size();){
            if(str1[i]!=lcs[k]){
                ans+=str1[i];
                i++;
            }
            else if(str2[j]!=lcs[k]){
                ans+=str2[j];
                j++;
            }
            else{
                ans+=lcs[k];
                i++;j++;k++;
            }
        }
        while(i<n)
            ans+=str1[i++];
        while(j<m)
            ans+=str2[j++];
        return ans;
    }
};