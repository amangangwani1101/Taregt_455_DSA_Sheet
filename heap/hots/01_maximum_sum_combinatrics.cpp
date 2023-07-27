#incldue<bits/stdc++.h>
using namespace std;


// 2 heap idea 
int f(vector<int>&a1,vector<int>&a2,int k){
    int n = a1.size(),m = a2.size();
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>st;
    pq.push({a1[n-1]+a2[m-1],{n-1,m-1}});
    st.insert({n-1,m-1});
    while(k){
        int sum = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        ans.push_back(sum);
        k--;
        if(st.find({x-1,y})==st.end()){
            pq.push({a1[x-1]+a2[y],{x-1,y}});
            st.insert({x-1,y});
        }
        if(st.find({x,y-1})==st.end()){
            pq.push({a1[x]+a2[y-1],{x,y-1}});
            st.insert({x,y-1});    
        }
    }
    return ans;
}


int main(){
    return 0;
}