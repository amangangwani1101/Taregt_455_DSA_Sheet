// Detailed Approach + Good Question

// Problem Article : https://takeuforward.org/data-structure/count-reverse-pairs/

// Problem Link :- https://leetcode.com/problems/reverse-pairs/

// Detailed Approach + Application Of Merge Sort

// Problem Article : https://takeuforward.org/data-structure/count-inversions-in-an-array/ 
// Problem Link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array


// inversion : in an array if i<j and arr[i]>arr[j]

#include<bits/stdc++.h>
using namespace std;

int cnt=0;

void mergeSort(vector<int>&arr,int low,int mid,int high){
    
    int l = low;
    int m = mid+1;
    vector<int>temp(high-low+1);
    
    int idx=0;
    for(;l<=mid and m<=high;idx++){
        if(arr[l]<=arr[m]){
            temp[idx] = arr[l++];
        }
        else {
            temp[idx] = arr[m++];
        }
    }

    while(l<=mid)
        temp[idx++] = arr[l++];
    while(m<=high)
        temp[idx++] = arr[m++];
    
    for(int ptr=low;ptr<=high;ptr++)
        arr[ptr] = temp[ptr-low];

    return ;
}

void countPairs(vector<int>&arr,int low,int mid,int high){
    int right = mid+1;
    for(int ptr=low;ptr<=mid;ptr++){
        while(right<=high and arr[ptr]>2*arr[right])
            right++;
        // cout<<(right-(mid+1))<<" ";
        cnt+=(right-(mid+1));
    }
}
void merge(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    merge(arr,low,mid);
    merge(arr,mid+1,high);
    countPairs(arr,low,mid,high);
    mergeSort(arr,low,mid,high);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge(arr,0,n-1);

    cout<<cnt<<endl;
    return 0;
}