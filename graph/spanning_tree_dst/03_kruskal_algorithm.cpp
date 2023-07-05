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


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        DisjointSet ds(V);
        vector<vector<int>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],i,it[0]});
            }
        }
        sort(edges.begin(),edges.end());
        int sumWeight=0;
        int m = edges.size();
        for(int i=0;i<m;i++){
            if(ds.findPar(edges[i][1])!=ds.findPar(edges[i][2])){
                sumWeight+=edges[i][0];
                ds.unionBySize(edges[i][1],edges[i][2]);
            }
        }
        return sumWeight;
    }
};