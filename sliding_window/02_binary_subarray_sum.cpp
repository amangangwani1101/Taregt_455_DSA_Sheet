#include<bits/stdc++.h>
using namespace std;

class CntSum{
private:
public:
    // prefix sum concept
    int numSubarraysWithSum(vector<int>&nums,int goal){
        int n = nums.size(),ans=0;
        vector<int>pre_sum(n+1,0);
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }
        for(int i=0;i<=n;i++){
            if(mp.find(pre_sum[i]-goal)!=mp.end()){
                ans+=mp[pre_sum[i]-goal];
            }
            mp[pre_sum[i]]++;
        }
        return ans;
    }

    // 2 pointer approach 
    int numSubarraysWithSum2(vector<int>&nums,int goal){
        int sum_high=0,sum_low=0,ilo=0,ihi=0,ans=0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            sum_low+=nums[j];
            while(ilo<j and sum_low>goal){
                sum_low-=nums[ilo++];
            }

            sum_high+=nums[j];
            while(ihi<j and (sum_high>goal or (sum_high==goal and nums[ihi]==0))){
                sum_high-=nums[ihi++];
            }

            if(sum_high==goal){
                ans+=(ihi-ilo+1);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}