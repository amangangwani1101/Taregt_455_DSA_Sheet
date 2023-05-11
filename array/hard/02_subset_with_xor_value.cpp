// Problem Stattement  : Given an array arr of N integers and an integer K, 
// find the number of subsets of arr having XOR of elements as K.

// Input:
// N = 4
// k = 6
// arr: 6 9 4 2
// Output:
// 2
// Explanation:
// The subsets are 
// {4,2} and {6}

// Problem Link : https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subsets-with-xor-value

// approach at every point we have 2 option either to take this element or not for xor 
// calculation so from here recursion  + dp starts

// ex : [6,9,4,2]
// f(index,xor_calc)  
//                                                            f(3,6)
//                     f(2,0)                                                                             f(2,6)
//            f(1,9)                        f(1,0)                                      f(1,15)                            f(1,6)   
//     f(0,13)      f(0,9)                f(0,4)  f(0,0)                    f(0,11)                 f(0,15)         f(0,2)         f(0,6)
// f(-1,15)  f(-1,13) f(-1,11) f(-1,9)f(-1,6) f(-1,4)  f(-1,2)  f(-1,0)  f(-1,9)  f(-1,11)  f(-1,13) f(-1,15) f(-1,0) f(-1,2)f(-1,4)  (-1,6)
//                                                              // ^                                              ^ 
                                                                // |                                              | 

// Ans 2  
// Time Complexity can be converted into exponential to O(n2) 

#include<bits/stdc++.h>
using namespace std;

int f(int arr[],int n,int xor_calc,vector<vector<int>>&dp){
    if(n<0) return (xor_calc==0);

    if(dp[n][xor_calc]!=-1) return dp[n][xor_calc];

    int take  = f(arr,n-1,xor_calc^arr[n],dp);
    int notTake = f(arr,n-1,xor_calc,dp);
    
    return dp[n][xor_calc] = take + notTake;
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    int n,k;
    cin>>n>>k;
    int arr[n];
    int xor_cal =0,max_xor=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        xor_cal ^=arr[i];
        max_xor = max(max_xor,xor_cal);
    }
    vector<vector<int>>dp(n,vector<int>(max_xor+1,-1));
    cout<<f(arr,n-1,k,dp)<<endl;
    return 0;
}