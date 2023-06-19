#include<bits/stdc++.h>
using namespace std;

class Question{
private:
    vector<int>parent;
public:
    
    bool dfs(vector<int>adj[],int node,int par,vector<int>&parent){
        if(parent[node]!=-1){
            return true;
        }
        parent[node] = par;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(dfs(adj,it,node,parent))
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>par(V,-1);
        for(int node =0;node<V;node++){
            if(par[node]==-1 and dfs(adj,node,-1)){
                return true;
            }
        }
        return false;
    }
};

// using disjoint set
class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    bool Union(int a,int b){
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa==pb) return true;
        if(rank[pa]>=rank[pb])
            parent[pb] = pa;
        else    
            parent[pa] = pb;
        return false;
    }
};


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        DSU ds(V);
        bool ans = false;
        map<pair<int,int>,bool>mp;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                if(!mp[{i,it}]){
                    mp[{i,it}] = 1;
                    mp[{it,i}] = 1;
                    ans |=ds.Union(i,it);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
};


int main(){

    return 0;
}