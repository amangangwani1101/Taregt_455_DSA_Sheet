// Follow All Approach

// Problem Article : https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/ 

// Problem Link : https://leetcode.com/problems/maximum-product-subarray/


// [1,-2,0,-3,4,-2]
// as maximum product of subarray lies in fact that 
// 1st priority subarray has all positive number  : take it
// 2nd priority subarray has even number of -ve sign : take it
// 3rd priority subarray has odd number of -ve sign : try to find and store 1st -ve and last -ve and divide it by product

// optimized approach
// at each iteration try to store maximum negative product subarray and maximum positive product subarrray
// as at particulatr iteration you get -ve sign swap maximum -ve product and maxuimum +ve product bcz after this iteartion max +ve product will become max negative and max -ve product will become max +ve

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
    
    int max_nVe=1,max_pVe=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<0) 
            swap(max_nVe,max_pVe);
        max_nVe = min(max_nVe*arr[i],arr[i]);
        max_pVe = max(max_pVe*arr[i],arr[i]);
        ans = max(ans,max_pVe);
    }
    cout<<ans<<endl;
    return 0;
}