#include<bits/stdc++.h>
using namespace std;


class Graph{
private:
    vector<int>ans,dist;
public:
    Graph(int n,int src){
        dist.resize(n,INT_MAX);
        ans.resize(n);
    }

    void dfs(int node,vector<vector<int>>adj[]){
        for(auto it:adj[node]){
            if(dist[it[0]]<=dist[node]+it[1]) continue;
            dist[it[0]] = dist[node]+it[1];
            dfs(it[0],adj);
        }
        return;
    }

    vector<int> retAns(){
        for(int i=0;i<dist.size();i++){
            ans[i] = dist[i]==INT_MAX?-1:dist[i];
        }
        return ans;
    }
    
    vector<int> bfs(int src,vector<vector<int>>adj[]){
        set<pair<int,int>>pq;
        st.insert({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it[0]]>dis+it[1])
                {
                    dist[it[0]] = dis+it[1];
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
        return retAns();
    }

};
int main(){
    return 0;
}