class Solution {
  public:
    
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)
            hash[i] = i;
        int maxi=1,lastIdx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] and dp[i]<(1+dp[j])){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        // cout<<maxi<<" ";
        vector<int>ans;
        ans.push_back(arr[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(arr[lastIdx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
