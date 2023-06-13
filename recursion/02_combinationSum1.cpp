#include<bits/stdc++.h>
using namespace std;


// Combination Sum - I
class Solution {
public:

    void findNumbers(vector<int>& ar, int sum,vector<vector<int> >& res, vector<int>& r,int i)
    {
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    while (i < ar.size() && sum - ar[i] >= 0) {
            findNumbers(ar, sum - ar[i], res, r, i);
            i++;
            r.pop_back();
        }
        
    }

    vector<vector<int> > combinationSum(vector<int>& ar,int sum)
    {
        // sort input array
        sort(ar.begin(), ar.end());

        // remove duplicates
        ar.erase(unique(ar.begin(), ar.end()), ar.end());

        vector<int> r;
        vector<vector<int> > res;
        findNumbers(ar, sum, res, r, 0);

        return res;
    }
};

// Combination Sum - II
class Solution2{
private:
    vector<int>candidates;
    vector<vector<int>>ans;
public:
    Solution2(vector<int>&temp){
        candidates = temp;
        sort(candidates.begin(),candidates.end());
    }

    void combinationSum2(int index,int target,vector<int>&temp){
        if(!target)
        {
            ans.push_back(temp);
            return;
        }
        if(index<0 or target<0) return;
        for(int idx = index;idx<candidates.size();idx++){
            if(idx>index and candidates[idx]==candidates[idx-1]) continue;
            temp.push_back(candidates[idx]);
            combinationSum2(idx+1,target-candidates[idx],temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> getMatrix(){
        return ans;
    }
};  

int main(){
    Solution2 * s = new Solution2(candidates);
    vector<int>temp;
    s->combinationSum2(0,target,temp);
    return s->getMatrix();      
    return 0;
}