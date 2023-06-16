// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/

// approach is preety much similar to largest rectangle in histogram for each index check how many element at left are greater than it , similarly check how many element are greater than it on right

#include<bits/stdc++.h>
using namespace std;

// largest rectangle in histogram extended version
class LRH{
public:
    void largestRectangle(vector<int>&arr){
        arr.push_back(0);
        int n = arr.size(),ans=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
                int left = st.size()?st.top()+1:0;
                int right = i;
                ans = max(ans,(right-left)*arr[i]);
            }
            st.push(i);
        }
    }    
};
int main(){
    return 0;
}

