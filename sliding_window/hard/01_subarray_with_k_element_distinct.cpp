#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&nums,int k){
    int i=0,j=0;
    int n = nums.size();
    vector<int>freq(n+1,0);
    while(j<n){
        if(k>=0){
            if(!freq[nums[j]])
                k--;
            freq[nums[j]]++;
        }
        if(k<0){
            while(i<=j and k<0){
                freq[nums[i]]--;
                if(!freq[nums[i]])
                    k++;
                i++;
            }
        }
        if(k>=0)
            ans+=(j-i+1);
    }
    return ans;
}
int main(){
    return f(nums,k) - f(nums,k-1);
}