// Problem Link : https://leetcode.com/problems/next-greater-element-ii/

// approach : if some how we can traverse array in reverse direction and maintain montonic decreasing order and then again traverse array this time your stack has all possible element from fron part of array and current part of array so you will get your answeer

// [1,2,3,4,3]

// Stack  : [3] - 1
// Stack  : [4] - 2
// Stack  : [3,4] - 3
// Stack  : [2,3,4] - 4
// Stack  : [1,2,3,4] - 5

// again traversing using same stack
// Stack  : [1,2,3,4] - 1
// Stack  : [3,4] - 2   Ans [4]
// Stack  : [4] - 3  Ans[-1,4]
// Stack  : [3,4] - 4 Ans [4,-1,4] 
// Stack  : [2,3,4] - 5 Ans [3,4,-1,4]
// Stack  : [1,2,3,4] - 6 Ans [2,3,4,-1,4]

#include <bits/stdc++.h>
using namespace std;

class Ques{
private:
    stack<int>st;
    vector<int>ans;
public:
    void nextGreaterInCircular(vector<int>&arr){
        int n = arr.size();
        ans.resize(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() and st.top()<=arr[i%n]){
                st.pop();
            }
            // start updation in array as i<n
            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return;
    }

    vector<int> print(){
        return ans;
    }
};

int main(){
    return 0;
}

