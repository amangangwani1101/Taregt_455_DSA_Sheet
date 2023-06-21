#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
private:
    vector<int>parent,rank;
public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    bool Union(int n1,int n2){
        int p1 = findPar(n1);
        int p2 = findPar(n2);
        if(p1==p2){
            return rank[n1]>=rank[n2];
        }
        parent[p1] = p2;
        rank[p2]+=(rank[p1]+1);
        return false;
    }
};
class Graph{
    vector<int>visit,dfsVisit;
public:    
    Graph(int n){
        visit.resize(n,0);
        dfsVisit.resize(n,0);
    }
    // dfs
    bool dfs(int node,vector<int>adj[]){
        if(dfsVisit[node])
            return true;
        if(visit[node])
            return false;
        visit[node]=dfsVisit[node]=1;
        for(auto it:adj[node]){
            if(dfs(it,adj))
                return true;
        }
        dfsVisit[node] = 0;
        return false;
    }
    // bfs 
    bool bfs(int V,vector<int>adj[]){
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(!indegree[i])
                q.push(i);
        }
        int node=0;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            node++;
            for(auto it:adj[n]){
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
        return !(V==node);
    }
    // dsu
    bool dsu(int V,vector<int>adj[]){
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                if(ds.Union(i,it))
                    return true;
            }
        }
        return false;
    }
    
    bool dfsUtil(int n,vector<int>adj[]){
        for(int i=0;i<n;i++){
            if(!visit[i] and dfs(i,adj))
                return true;
        }
        return false;
    }
};
int main(){

    return 0;
}