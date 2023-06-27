#incldue<bits/stdc++.h>
using namespace std;


class Graph{
private:
        vector<vector<int>>grid,vis;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
public:
    Graph(int n,int m,vector<vector<int>>&g){
        grid = g;
        vis.resize(n,vector<int>(m,1e9));
    }
    bool isSafe(int r,int c){
        return (r>=0 and c>=0 and r<grid.size() and c<grid[0].size());
    }
    int dir[5] = {-1,0,1,0,-1};
    int bfs(){
        pq.push({0,{0,0}});
        vis[0][0] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==grid.size()-1 and c==grid[0].size()-1)
                return dist;
            for(int k=0;k<4;k++){
                int nr = r + dir[k];
                int nc= c + dir[k+1];
                if(isSafe(nr,nc) and vis[nr][nc]>max(dist,abs(grid[nr][nc]-grid[r][c]))){
                    int newEff = max(dist,abs(grid[nr][nc]-grid[r][c]));
                    vis[nr][nc] = newEff;
                    pq.push({newEff,{nr,nc}});
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n = g.size(),m = g[0].size();
        Graph gp(n,m,g);
        return gp.bfs();
    }
};
int main(){
    return 0;
}