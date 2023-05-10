// given an array arr  = [4,5,3,1,1]
// find its next permutation Ans :- [5,1,1,3,4] 


// Problem Link:- https://leetcode.com/problems/next-permutation/description/
// Article Link :- https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/ 

// intuttion  : -
// step 1 : find breakaway point where arr[i]<arr[i+1] : idx is a breakaway point
// step 2 : find element which is least greater than arr[idx] in range of [idx+1 - n-1 ] swap arr[idx] , arr[el] 
// step 3 : reverse range of array of idx+1 to n-1



#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // step 1 : 
    int idx = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1])
        {
            idx = i;
            break;
        }
    }
    // if arary is already sorted than return in sorted order increasing
    if(idx==-1)
        reverse(arr,arr+n);
    else{
        // step 2
        for(int i = n-1;i>idx;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }

        // step 3
        for(int i=0;i<(n-1-idx)/2;i++)
            swap(arr[i+idx+1],arr[n-1-i]);
    }

    // output array
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
    return 0;
}