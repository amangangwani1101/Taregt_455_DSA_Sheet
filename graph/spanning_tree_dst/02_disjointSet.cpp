#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int>parent,rank,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank = size = parent;
        for(int i=0;i<=n;i++){
            rank[i] = size[i] = 1;
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int nodeA,int nodeB){
        int ulp_nodeA = findPar(nodeA);
        int ulp_nodeB = findPar(nodeB);

        if(ulp_nodeA==ulp_nodeB)    
            return;

        if(rank[ulp_nodeA]==rank[ulp_nodeB]){
            parent[ulp_nodeA] = ulp_nodeB;
            rank[ulp_nodeB]++;
        }

        else if(rank[ulp_nodeA]>rank[ulp_nodeB]){
            parent[ulp_nodeB] = ulp_nodeA;
        }

        else{
            parent[ulp_nodeA] = ulp_nodeB;
        }
    }


    void unionBySize(int nodeA,int nodeB){
        int ulp_nodeA = findPar(nodeA);
        int ulp_nodeB = findPar(nodeB);

        if(ulp_nodeA==ulp_nodeB)    
            return;

        if(size[ulp_nodeA]<size[ulp_nodeB]){
            parent[ulp_nodeA] = ulp_nodeB;
            size[ulp_nodeB]+=size[ulp_nodeA];
        }

        else{
            parent[ulp_nodeB] = ulp_nodeA;
            size[ulp_nodeA]+=size[ulp_nodeB];
        }
    }
    
};

int main(){


    return 0;
}