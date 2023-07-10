#include<bits/stdc++.h>
class MCM{
private:
    vector<vector<int>>dp;
public:
    MCM(int n){
        dp.resize(n,vector<int>(n,0));
    }
    int mcm_memo(int *arr,int i,int j){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            mini = min(mini,arr[i-1]*arr[k]*arr[j] + mcm_memo(arr,i,k) + 
            mcm_memo(arr,k+1,j));
        }
        return dp[i][j] = mini;
    }

    int mcm_tabu(int *arr,int n){
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                int mini = INT_MAX;
                for(int k=i;k<j;k++){
                    mini = min(mini,arr[i-1]*arr[k]*arr[j] + dp[i][k] + 
                    dp[k+1][j]);
                }
                dp[i][j] = mini==INT_MAX?0:mini;
            }
        }
        return dp[1][n];
    }
};
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    MCM mcm(n+1);
    return mcm.mcm_tabu(arr,n);
}