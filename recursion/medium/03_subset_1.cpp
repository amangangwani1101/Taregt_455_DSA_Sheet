#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int>ans;
public:
    void subset1(vector<int>&arr,int idx,int sum){
        if(idx==arr.size()) {
            ans.push_back(sum);
            return;
        }
        subset1(arr,idx+1,sum);
        subset1(arr,idx+1,sum+arr[idx]);
        return;
    }

    vector<int> getMatrix(){
        return ans;
    }
};
int main(){

    return 0;
}