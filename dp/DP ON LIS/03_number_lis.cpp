#include<bits/stdc++.h>
using namespace std;

class Ques{
private:
    vector<int>dp(n,1),cnt(n,1);
public:
    ing cnt_lis(vector<int>&nums){
        int n = nums.size();
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<(1+dp[j])){
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i]==(1+dp[j])){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}