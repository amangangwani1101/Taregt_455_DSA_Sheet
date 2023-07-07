class LIS{
private:
    vector<vector<int>>dp;
public:
    LIS(int n){
        dp.resize(n+2,vector<int>(n+1,0));
    }

    int lis(vector<int>&nums,int idx,int prev){
        if(idx==nums.size()+1)
            return 0;
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        int op1=0,op2=0;
        op1 = lis(nums,idx+1,prev);
        if(prev==0 or nums[idx-1]>nums[prev-1])
            op2 = 1 + lis(nums,idx+1,idx);
        return dp[idx][prev] = max(op1,op2);
    }

    int lis_tabu(vector<int>&nums){
        
        int n = nums.size();
        for(int i=n;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                int op1=0,op2=0;
                op1 = dp[i+1][j];
                if(j==0 or nums[i-1]>nums[j-1])
                    op2 = 1 + dp[i+1][i];
                dp[i][j] = max(op1,op2);                            
            }
        }
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[1][0];
    }

    // using binary search 
    int lis_bs(vector<int>&nums){
        vector<int>store;
        int n = nums.size(),ans=0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(store.begin(),store.end(),nums[i]);
            if(it==store.end()){
                ans++;
                store.push_back(nums[i]);
            }
            else{
                store[it-store.begin()] = nums[i];
            }
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        LIS l(n);
        return l.lis_bs(nums);
    }
};