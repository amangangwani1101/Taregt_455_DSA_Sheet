#include<bits/stdc++.h>
using namespace std;

    class DP{
    private:
        vector<int>arr;
        vector<vector<int>>dp;
    public:
        DP(vector<int>&a,int tgt){
            arr = a;
            dp.resize(a.size(),vector<int>(tgt+1,0));
        }

        // memoization
        bool subsetSum1(int idx,int tgt){
            if(tgt<0) return 0;
            if(!tgt) return 1;
            if(!idx) return tgt==arr[idx];
            if(dp[idx][tgt]!=-1) return dp[idx][tgt];
            bool choice1 = subsetSum1(idx-1,tgt);
            bool choice2 = subsetSum1(idx-1,tgt-arr[idx]);
            return dp[idx][tgt] =choice1|choice2;
        }

        // tabulation
        bool subsetSum2(int n,int tgt){
            if(arr[0]<=tgt)
                dp[0][arr[0]]=1;
            for(int i=0;i<n;i++)
                dp[i][0] = 1;
            for(int i=1;i<n;i++){
                for(int t=1;t<=tgt;t++){
                    bool choice1 =false,choice2 = false;
                    choice1 = dp[i-1][t];
                    if(t-arr[i]>=0)
                        choice2 = dp[i-1][t-arr[i]];
                    dp[i][t] = choice1|choice2;
                }
            }
            return dp[n-1][tgt];
        }

        // tabulation+space_optimization
        bool subsetSum3(int n,int tgt){
            vector<int>prev(tgt+1,0);
            if(arr[0]<=tgt)
                prev[arr[0]]=1;
            prev[0] = 1;
            for(int i=1;i<n;i++){
                for(int t=tgt;t>=1;t--){
                    bool choice1 =false,choice2 = false;
                    choice1 = prev[t];
                    if(t-arr[i]>=0)
                        choice2 = prev[t-arr[i]];
                    prev[t] = choice1|choice2;
                }
            }
            return prev[tgt];
        }
    };


int main(){
    return 0;
}