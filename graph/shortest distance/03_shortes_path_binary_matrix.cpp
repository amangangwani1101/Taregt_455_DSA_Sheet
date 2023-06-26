#include<bits/stdc++.h>
using namespace xtd;

class Graph{
private:
    vector<vector<int>>grid;
    queue<pair<int,int>>q;
    int dx[3] = {-1,0,1};dy[3] = {-1,0,1};
public:
    Graph(int n,int m,vector<vector<int>>&g){
        grid = g;
        dp.resize(n,vector<int>(m,0));
    }

    bool isSafe(int r,int c){
        return (r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==0 and !dp[r][c]);
    }

    int bfs(int r,int c){
        q.push({0,0});
        dp[0][0]=1;
        int time=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r==grid.size()-1 and c==grid[0].size()-1)
                    return time;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        int nr = r + dx[x];
                        int nc = c + dy[y];
                        if(isSafe(nr,nc)){
                            q.push({nr,nc});
                            dp[nr][nc] = 1;
                        }
                    }
                }
            }
            time++;
        }
        return ans;
    }
    return -1;
};
int main(){
    return 0;
}