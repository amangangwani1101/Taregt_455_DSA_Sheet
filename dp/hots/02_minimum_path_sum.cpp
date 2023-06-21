//  Problem Link: https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1?

int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        // ,greater<pair<int,pair<int,int>>>>q;
        set<pair<int,pair<int,int>>>st;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        st.insert({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        int dir[5] = {-1,0,1,0,-1};
        while(!st.empty()){
            int dis = (*st.begin()).first;
            int r = (*st.begin()).second.first;
            int c = (*st.begin()).second.second;
            st.erase(st.begin());
            if(r==n-1 and c==m-1) return dis;
            for(int k=0;k<4;k++){
                int nr = r + dir[k];
                int nc = c + dir[k+1];
                if(nr>=0 and nc>=0 and nr<n and nc<m and dist[nr][nc]>grid[nr][nc]+dis){
                    st.erase({dist[nr][nc],{nr,nc}});
                    dist[nr][nc] = grid[nr][nc]+dis;
                    st.insert({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }