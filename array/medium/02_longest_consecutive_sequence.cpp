// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

// Problme Link : https://leetcode.com/problems/longest-consecutive-sequence/submissions/

// Example 1:

// Input: [100, 200, 1, 3, 2, 4]

// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// Input: [3, 8, 5, 7, 6]

// Output: 4

// Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.

// appraoch : either use map or set 
// step 1 : first traverse array and store in either of data structure
// step 2 : then simple cnt how many consecutive elemnt are present in array using ds 
// * now from which element couunt should be start bcz if start from 2 and further in array 1 comes then again counting sso time complexity increases so to avoid it we check if (el-1) donot exist in array usin ds then start from that element only by this repetitive counting can be save

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
    
    unordered_set<int>st;
    //  step 1 : 
    for(int i=0;i<n;i++)
        st.insert(arr[i]);
    
    // step 2:
    int ans=0;
    for(int i=0;i<n;i++){
        int el = arr[i];
        // to avoid repetitive count 
        int cnt=0;
        if(!st.count(el-1)){
            cnt=1;
            while(st.count(el+1)){
                cnt++;
                el++;
            }
            ans = max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}