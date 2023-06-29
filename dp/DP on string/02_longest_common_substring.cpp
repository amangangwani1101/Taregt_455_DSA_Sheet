class DP {
        private:
            vector<vector<int>>dp;
        public:
            DP(int n,int m){
                dp.resize(n+1,vector<int>(m+1,0));
            }
        
            // tabulation
            int lcsTabu(string &s,string &t,int n,int m){
                int maxi=0;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(s[i-1]==t[j-1]){
                            dp[i][j] = 1 + dp[i-1][j-1];
                            maxi = max(maxi,dp[i][j]);
                        }
                    }
                }
                return maxi;
            }
    };