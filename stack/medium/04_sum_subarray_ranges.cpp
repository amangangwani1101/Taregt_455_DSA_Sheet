// Problm Link : https://leetcode.com/problems/sum-of-subarray-ranges/

// approach is preety much similar to previous problem sum of subarray minimum 

// main problem is we have to find difference of minimum and maximum of all subarray so try to mold problem if somehow we can find contributuion of each element in maximum part of subarray and similarly contribution of each element in minimum part of subarray then by returing their difference will solve our problem

// example arr = [4,-2,-3,4,1]
// left maximum contributon  [0,0,0,2,0]
// right maximum contributon [4,1,0,1,0]
// left minimum contributon  [0,1,2,0,1]
// right minimum contributon [0,0,2,0,0]

// maxContributon=(arr[i]*((leftMax[i]+1)*(rightMax[i]+1)-1))
// minContributon=(arr[i]*((leftMin[i]+1)*(rightMin[i]+1)-1))

// return (maxContribution - minContribution)

// maxcontribution = (16 + -2 + 20) => 34 
// minContribution = (-2 + -24 + 1) => -25

// maxContribution - minContribution => 34+25 = 59

#include<bits/stdc++.h>
using namespace std;

class Ques{
private:
    vector<int>left,right;
    stack<int>leftStore,rightStore;
    bool toggle = false;
public:
    int subarrayContribution(vector<int>&arr,bool cond){
        int n = arr.size();
        left.resize(n,0);
        right.resize(n,0);
        toggle = cond;
        // left traversal 
        for(int i=0;i<n;i++){
            while(!leftStore.empty() and ((!cond and arr[leftStore.top()]<arr[i]) or 
            (cond and arr[leftStore.top()]>=arr[i])))
                leftStore.pop();
            left[i] = (leftStore.size()>0)?i - leftStore.top()-1:i;
            leftStore.push(i);
        }

        // right traversal 
        for(int i=n-1;i>=0;i--){
            while(!rightStore.empty() and ((!cond and arr[rightStore.top()]<=arr[i]) or (cond and arr[rightStore.top()]>arr[i])))
                rightStore.pop();
            right[i] = (rightStore.size()>0)?rightStore.top()-i-1
            :n-i-1;
            rightStore.push(i);
        }

        int contribution  = 0;

        for(int i=0;i<n;i++){
            contribution+=(arr[i]*((left[i]+1)*(right[i]+1)-1));
        }

        return contribution;
    }
};