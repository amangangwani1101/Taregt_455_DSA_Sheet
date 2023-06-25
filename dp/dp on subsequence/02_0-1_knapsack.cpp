#include<bits/stdc++.h>
using namespace std;

class DP{
private:
    vector<vector<int>>dp;
public:
    DP(int n,int w){
        dp.resize(n,vector<int>(w+1,-1));
    }
    // memoization
    int knapSack1(int W,int wt[],int val[],int idx){
        if(idx<0) return 0;
        if(W<0) return -1e4;
        if(dp[idx][W]!=-1) return dp[idx][W];
        int choice1 = knapSack1(W,wt,val,idx-1);
        int choice2 = val[idx] + knapSack1(W-wt[idx],wt,val,idx-1);
        return dp[idx][W] = max(choice1,choice2);
    }

    // tabulation
    int knapSack2(int W,int wt[],int val[],int n){
        if(W>=wt[0])
            dp[0][wt[0]] = val[0];
        for(int i=0;i<n;i++)
            dp[i][0] = 0;
        for(int i=1;i<n;i++){
            for(int w=1;w<=W;w++){
                    int choice1 = dp[i-1][w];
                    int choice2=0;
                    if(w>=arr[i])
                        choice2 = val[i] + dp[i-1][w-arr[i]];
                    dp[i][w] = max(choice1,choice2);
            }
        }
        return dp[n-1][W];
    }

    int knapSack3(int W,int wt[],int val[],int n){
        vector<int>curr(W+1,0);
        if(W>=wt[0])
            curr[wt[0]] = val[0];
        curr[0] = 0;
        for(int i=1;i<n;i++){
            for(int w=W;w>=1;w--){
                    int choice1 = curr[w];
                    int choice2=0;
                    if(w>=arr[i])
                        choice2 = val[i] + curr[w-arr[i]];
                    curr[w] = max(choice1,choice2);
            }
        }
        return curr[W];
    }

};
int main(){
    
    return 0;
}