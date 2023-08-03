#include<bits/stdc++.h>
using namespace std;

// 3 different ways 

// 1st : using map (ordered map) => to maintain consecutive behaviour of array
bool isNStraightHand(vector<int>& nums, int size) {
    map<int,int>mp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }

    while(!mp.empty()){
        auto it = mp.begin()->first;
        if(mp.find(it)!=mp.end() and mp.find(it-1)==mp.end()){
            int sz = size;
            while(mp.find(it)!=mp.end() and sz>0){
                mp[it]--;
                if(!mp[it]) 
                    mp.erase(it);
                sz--;
                it++;
            }
            if(sz>0) return false;
        }
    }
    return true;
    }

// 2nd using multiset 
bool isNStraightHand(vector<int>& nums, int size) {
        int n = nums.size();
        multiset<int>mt;
        for(int i=0;i<n;i++)
            mt.insert(nums[i]);
        
        while(!mt.empty()){
            auto it = *mt.begin();
            if(mt.find(it)!=mt.end() and mt.find(it-1)==mt.end()){
                int sz = size;
                while(mt.find(it)!=mt.end() and sz>0)
                {
                    mt.erase(mt.find(it));
                    it++;
                    sz--;
                }
                if(sz>0) return false;
            }
        }
        return true;
        }


// using priority queue 
    bool isNStraightHand(vector<int>& nums, int size) {
    // using priority queue 
    int n = nums.size();
    if(n%size) return false;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[nums[i]]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq,pq2;
    for(auto it:mp){
        pq.push({it.first,it.second});
    }
    while(!pq.empty()){
        int start = pq.top().first;
        int tot = pq.top().second;
        for(int gp=0;gp<size;gp++){
            if(pq.empty() or pq.top().first!=start) return false;
            tot = min(tot,pq.top().second);
            pq2.push(pq.top());
            pq.pop();    
            start++;
        }

        while(!pq2.empty()){
            if(pq2.top().second-tot>0){
                pq.push({pq2.top().first,pq2.top().second-tot});
            }
            pq2.pop();
        }
    }
    return true;
}

int main(){
    return 0;
}