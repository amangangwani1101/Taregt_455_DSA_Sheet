class DisjointSet {
public:
    vector<int>parent;
    DisjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void Union(int a,int b){
        int ulp_a = findPar(a);
        int ulp_b = findPar(b);
        parent[ulp_a] = ulp_b;
    }
};


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        int dir[5] = {-1,0,1,0,-1};
        while(!pq.empty()){
            int dis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 and c==m-1)
                return dis;
            for(int k=0;k<4;k++){
                int nr = r + dir[k];
                int nc = c + dir[k+1];
                if(nr>=0 and nc>=0 and nr<n and nc<n and dist[nr][nc]>(max(grid[nr][nc],dis))){
                    dist[nr][nc] = (max(grid[nr][nc],dis));
                    pq.push({dist[nr][nc],{nr,nc}});
                } 
            }
        }
        return -1;
    }
};



class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        DisjointSet ds(n*n);
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edges.push_back({grid[i][j],i,j});
            }
        }
        int dir[5] = {-1,0,1,0,-1};
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            int r = edges[i][1],c = edges[i][2],node = n*r+c;
            for(int k=0;k<4;k++){
                int nr = r + dir[k];
                int nc = c + dir[k+1];
                if(nr>=0 and nc>=0 and nr<n and nc<n and grid[r][c]>grid[nr][nc]){
                    // cout<<node<<" "<<nr<<" "<<nc<<endl;
                    ds.Union(node,nr*n+nc);
                }
                if(ds.findPar(0)==ds.findPar((n*n)-1))
                    return grid[r][c];
            }
        }
        return -1;
    }
};