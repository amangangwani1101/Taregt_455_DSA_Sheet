// Problem Link : https://leetcode.com/problems/sum-of-subarray-minimums/

// approach is preety much similar to largest rectangle in histogram for each index check how many element at left are greater than it , similarly check how many element are greater than it on right

#include<bits/stdc++.h>
using namespace std;

// TRH :- largest rectangle in histogram
class TRH{
private:
    int N = 1e9+7;
    vector<int>left,right;
    stack<int>leftStack,rightStack;
public:
    int trhVersion(vector<int>&arr){
        int n = arr.size();
        long ans=0;
        left.resize(n+2,0);
        right.resize(n+2,0);
        arr.insert(arr.begin(),0);
        arr.push_back(0);
        // left traversal
        n = arr.size()-1;
        for(int i=0;i<=n;i++){
            while(!leftStack.empty() and arr[leftStack.top()]>=
            arr[i])
                leftStack.pop();
            left[i] = (leftStack.size()>0)?i - leftStack.top()-1:0;
            leftStack.push(i);
        }

        // right traversal
        for(int i=n;i>=0;i--){
            while(!rightStack.empty() and arr[rightStack.top()]>
            arr[i])
                rightStack.pop();
            right[i] = (rightStack.size()>0)?rightStack.top()-i-1:0;
            rightStack.push(i);
        }

        // for(int i=1;i<n;i++) cout<<left[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<n;i++) cout<<right[i]<<" ";

        for(int i=1;i<n;i++){
            long pro = ((left[i]+1)*(right[i]+1))%N;
            ans=(ans%N + (arr[i]*pro)%N)%N;
        }
        return (int)ans;
    }
};

int main(){
    return 0;
}

