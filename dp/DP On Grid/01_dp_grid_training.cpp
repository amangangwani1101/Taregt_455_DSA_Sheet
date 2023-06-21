#include<bits./stdc++.h>
using  namespace std;


class DPGrid{
private:
    vector<vector<int>>grid;
    vector<vector<int>>dp;
    vector<int>prev,curr;
public:
    DPGrid(vector<vector<int>>&point){
        grid = point;
        int n = grid.size();
        prev.resize(3,-1);
        curr.resize(3,-1);
        dp = vector<vector<int>>(n,vector<int>(3,0));
    }

    int maxPointsMemo(int idx,int st){
        if(idx<0) return 0;
        if(dp[idx][st]!=-1) return dp[idx][st];
        int maxPoints = 0;
        for(int i=0;i<3;i++){
            if(st==i) continue;
            maxPoints = max(maxPoints,grid[idx][i]+maxPointsMemo(idx-1,i));
        }
        return dp[idx][st] = maxPoints;
    }
    
    int maxPointsTab(){
        int n = grid.size();
        for(int i=0;i<3;i++)
            dp[0][i] = grid[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][j] = grid[i][j];
                if(j==0) dp[i][j]+=max(dp[i-1][1],dp[i-1][2]);
                else if(j==1) dp[i][j]+=max(dp[i-1][0],dp[i-1][2]);
                else dp[i][j]+=max(dp[i-1][1],dp[i-1][0]);
            }
        }
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
    
    int maxPointsTab_Space(){
        int n = grid.size();
        for(int i=0;i<3;i++)
            prev[i] = grid[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                curr[j] = grid[i][j];
                if(j==0) curr[j]+=max(prev[1],prev[2]);
                else if(j==1) curr[j]+=max(prev[0],prev[2]);
                else curr[j]+=max(prev[1],prev[0]);
            }
            prev = curr;
        }
        return max({prev[0],prev[1],prev[2]});
    }
    
    
    int maxPoints(){
        int maxi=0,n = grid.size();
        for(int i=0;i<3;i++){
            maxi = max(maxi,grid[n-1][i] + maxPointsMemo(n-2,i));
        }
        return maxi;
    }
};

int main(){

    return 0;
}