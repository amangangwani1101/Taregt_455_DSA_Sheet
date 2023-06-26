#include<bits/stdc++.h>
using namespace std;

class Question{
private:
    vector<vector<int>>ans;
    queue<pair<int,int>>q;
    vector<vector<int>>grid;
public:
    Question(vector<vector<int>>&gridd){
        grid = gridd;
        ans = vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),INT_MAX));    
    }
    void nearestDistance()
    {
        int n = grid.size(), m =grid[0].size();
        // vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int dir[5] = {-1,0,1,0,-1};
        int dist=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr = r + dir[k];
                    int nc = c + dir[k+1];
                    if(nr>=0 and nc>=0 and nr<n and nc<m and grid[nr][nc]==0 and ans[nr][nc]==INT_MAX){
                        q.push({nr,nc});
                        ans[nr][nc] = 1 + dist;
                    }
                }
            }
            dist++;
        }
    }

    vector<vector<int>> getAns(){
        return ans;
    }
};

//optimized approach 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};
int main(){

    return 0;
}