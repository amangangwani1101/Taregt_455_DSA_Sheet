#include<bits/stdc++.h>
using namespace std;

// approach 1 using priority_queue + hashmap TC(O(NlogN)) SC (O)(N)) -- easy

// approach 2 using quick sort algorithm 

int partitian(vector<int>&nums,int l,int r,unordered_map<int,int>&count){
    int s = l;
    l++;
    do{

        while(l<=r and count[nums[l]]<=count[nums[s]])
            l++;
        while(r>=l and count[nums[r]]>count[nums[s]])
            r--;
        if(l<=r)
            swap(nums[l],nums[r]);
    }while(l<=r);
    swap(nums[s],nums[right]);
    return right;
}
void modifyQuickSort(vector<int>&nums,int left,int right,int k){
    if(left>right)
        return;
    int partitian = partitianPoint(nums,left,right);
    if(nums.size()-partitian==k){
        return;
    }
    else if(nums.size()-partitian<k){
        modifyQuickSort(nums,left,partitian-1,k);
        return;
    }
    modifyQuickSort(nums,partitian+1,right,k);
    return;
}

int KMostFrequent(vector<int>&nums,int k){
    vector<int>unique;
    vector<int>ans;
    int n = nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(!mp[nums[i]])
            unique.push_back(nums[i]);
        mp[nums[i]]++;
    }
    modifyQuickSort(unique,0,unique.size()-1,k);
    while(k--){
        ans.push_back(unique.back());
        unique.pop_back();
    }
    return ans;
}
int main(){

    return 0;
}