#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<int>ans,dist;
public:

    Graph(int n){
        dist.resize(n,INT_MAX);
        ans.resize(n);
        dist[0] = 0;
    }
    // bfs using priority_queue
    vector<int> bfs(vector<pair<int,int>>adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                   dist[it.first] = dis+it.second;
                   pq.push({dist[it.first],it.first}); 
                }
            }
        }
        
        for(int i=0;i<dist.size();i++){
            ans[i] = dist[i]==INT_MAX?-1:dist[i];
        }
        return ans;
    }

    // bfs using set
    vector<int> bfs2(vector<pair<int,int>>adj[]){
        set<pair<int,int>>st;
        st.insert({0,0});
        dist[0] = 0;
        while(!st.empty()){
            int dis = (*st.begin()).first;
            int node = (*st.begin()).second;
            st.erase(st.begin());
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    if(dist[it.first]!=INT_MAX)
                        st.erase(st.find({dist[it.first],it.first})); 
                    dist[it.first] = dis+it.second;
                    st.insert({dist[it.first],it.first}); 
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            ans[i] = dist[i]==INT_MAX?-1:dist[i];
        }
        return ans;
    }
    
    void dfs(int node,vector<pair<int,int>>adj[]){
        for(auto it:adj[node]){
            if(dist[it.first]<=dist[node]+it.second) continue;
            dist[it.first] = dist[node]+it.second;
            dfs(it.first,adj);
        }
        return;
    }
    vector<int> retAns(){
        for(int i=0;i<dist.size();i++){
            ans[i] = dist[i]==INT_MAX?-1:dist[i];
        }
        return ans;
    }

    // more optimal approach  : using topological sort
    // a node will have a reduced distance from source if all nodes pointing to it have reduced distance from source so a dependency is formed between previous nodes means topp sort comes in play to ptovide order of nodes

    vector<int>  topo(vector<pair<int,int>>adj[]){
        vector<int>topoSort;
        queue<int>q;
        vector<int>indegree(dist.size());
        for(int i=0;i<dist.size();i++){
            for(auto it:adj[i])
                indegree[it.first]++;
        }
        for(int i=0;i<dist.size();i++){
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto it:adj[node]){
                indegree[it.first]--;
                if(!indegree[it.first])
                    q.push(it.first);
            }
        }

        dist[0] = 0;
        for(int i=0;i<topoSort.szie();i++){
            int node = topoSort[i];
            for(auto it:adj[node]){
                dist[it.first] = it.second + dist[node]; 
            }
        }
        return retAns();
    }
};


int main(){
    return 0;
}