
// Problem Link : https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?


#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    queue<vector<int>>pq;
    vector<int>dist;
public:
    Graph(int n){
        dist.resize(n,INT_MAX);
    }

    void bfs(int k,int src,vector<pair<int,int>>adj[]){
        dist[src] = 0;
        pq.push({k,0,src});
        while(!pq.empty()){
            int dis = pq.front()[1];
            int node = pq.front()[2];
            int stop = pq.front()[0];
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it.first]>dis + it.second and stop>=0){
                    dist[it.first] = dis+it.second;
                    pq.push({stop-1,dist[it.first],it.first});
                }
            }
        }
    }

    int retAns(int dst){
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
int main(){
    vector<pair<int,int>>adj[];
    return 0;
}