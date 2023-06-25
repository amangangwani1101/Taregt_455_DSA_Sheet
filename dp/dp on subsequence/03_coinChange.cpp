lass DP{
private:
    vector<vector<int>>dp;
public:
    DP(int n,int amt){
        dp.resize(n,vector<int>(amt+1,0));
    }

    // memoization
    int coinChange1(int idx,int amt,vector<int>&coins){
        if(!amt) return 0;
        if(amt<0) return INT_MAX;
        if(idx==0) return (amt%coins[idx])?INT_MAX:amt/coins[idx];
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int choice1 = coinChange1(idx-1,amt,coins);
        int choice2 = coinChange1(idx,amt-coins[idx],coins);
        if(choice2!=INT_MAX) choice2+=1;
        return dp[idx][amt] = min(choice1,choice2);
    }

    // tabulation
    int coinChange2(int n,int amt,vector<int>&coins){
        for(int i=0;i<n;i++)
            dp[i][0] = 0;
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0)
                dp[0][i] = i/coins[0];
            else
                dp[0][i] = INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int a=1;a<=amt;a++){
                int choice1 = dp[i-1][a];
                int choice2 = INT_MAX;
                if((a-coins[i])>=0 and dp[i][a-coins[i]]!=INT_MAX)
                    choice2 = 1+dp[i][a-coins[i]];
                dp[i][a] = min(choice1,choice2);                    
            }
        }
        return dp[n-1][amt];
    }

    // tabulation + space optimization
    int coinChange3(int n,int amt,vector<int>&coins){
        vector<int>curr(amt+1,0),prev(amt+1,0);
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0)
                prev[i] = i/coins[0];
            else
                prev[i] = INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int a=1;a<=amt;a++){
                int choice1 = prev[a];
                int choice2 = INT_MAX;
                if((a-coins[i])>=0 and curr[a-coins[i]]!=INT_MAX)
                    choice2 = 1+curr[a-coins[i]];
                curr[a] = min(choice1,choice2);                    
            }
            prev=curr;
        }
        return prev[amt];
    }
};

class Solution {
public:
    int f(int sum,vector<int>&nums,int i,int t,vector<vector<int>>&dp)
    {
        if(i==nums.size()) return (sum==t);
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];
        return dp[i][sum+1000] = f(sum+nums[i],nums,i+1,t,dp) + f(sum-nums[i],nums,i+1,t,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int m = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(m+1001,-1));
        return f(0,nums,0,target,dp); 
    }
};