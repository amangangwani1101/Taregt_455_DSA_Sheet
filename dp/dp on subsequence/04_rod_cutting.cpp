#include<bits/stdc++.h>
using namespace std;

class DP{
private:
    vector<vector<int>>dp;
public:

    DP(int n,int len){
        dp.resize(n,vector<int>(len+1,-1));
    }
    // memoization
    int rodCutting1(int idx,int rodLength,vector<int>&price){
        if(!rodLength) return 0;
        if(rodLength<0) return -price[idx];
        if(idx==0) return rodLength*price[idx];
        if(dp[idx][rodLength]!=-1) return dp[idx][rodLength];
        int choice1 = f(idx-1,rodLength,price);
        int choice2 = price[idx] + f(idx,rodLength-(idx+1),price);
        return dp[idx][rodLength] = max(choice1,choice2); 
    }

    int rodCutting2(int n,int rodLength,vector<int>&price){
        for(int i=0;i<n;i++)
            dp[i][0] = 0;
        for(int len=0;len<=rodLength;len++)
            dp[0][len] = len*price[0];
        for(int i=1;i<n;i++){
            for(int amt=1;amt<=rodLength;amt++){
                int choice1 = dp[i-1][amt];
                int choice2=0;
                if(amt>=(i+1))
                    choice2 = price[i] + dp[i][amt-(i+1)];
                dp[i][amt] = max(choice1,choice2);             
            }
        }
        return dp[n-1][rodLength];
    }

};
int main(){

    return 0;
}