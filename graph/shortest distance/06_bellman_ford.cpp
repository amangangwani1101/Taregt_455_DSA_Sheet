class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S] = 0;
        for(int relax=0;relax<V-1;relax++){
            for(auto it:edges){
                if(dist[it[0]]+it[2]<dist[it[1]])
                    dist[it[1]] = dist[it[0]]+it[2];
            }
        }
        // check for -ve cycle
        for(auto it:edges){
            if(dist[it[0]]+it[2]<dist[it[1]])
                return {-1};
        }
        return dist;
    }
};