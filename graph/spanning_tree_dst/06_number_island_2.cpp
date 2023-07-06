class DisjointSet{
private:
    vector<int>parent;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }   
    
    int findPar(int a){
        if(parent[a]==a)
            return a;
        return parent[a] = findPar(parent[a]);
    }
    
    void Union(int a,int b){
        int ulp_a = findPar(a);
        int ulp_b = findPar(b);
        if(ulp_a==ulp_b)
            return;
        parent[ulp_b] = ulp_a;
    }
};
class Ques{
private:
    vector<vector<int>>vis;
public:
    Ques(int n,int m){
        vis.resize(n,vector<int>(m,0));
    }
    
    int dx[3] = {-1,0,1},dy[3] = {-1,0,1};
    int component(vector<vector<char>>&grid){
        int n = grid.size(),m = grid[0].size();
        DisjointSet ds(n*m);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    int node1 = i*m+j,node2=-1;
                    vis[i][j] = 1;
                    cnt++;
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            if(k==1 and l==1) continue;
                            int ni=i+dx[k],nj=j+dy[l];
                            if(ni>=0 and nj>=0 and ni<n and nj<m and grid[ni][nj]=='1' 
                            and vis[ni][nj]){
                                node2 = ni*m+nj;
                                if(ds.findPar(node1)!=ds.findPar(node2)){
                                    ds.Union(node1,node2);
                                    cnt--;
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(),m = grid[0].size();
        Ques q(n,m);
        return q.component(grid);
    }
};