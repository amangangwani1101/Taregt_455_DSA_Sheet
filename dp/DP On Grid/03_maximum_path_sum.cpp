#includde<bits/stdc++.h>
using namespace std;

class DPGrid{
private:
    vector<vector<int>>mat;
    vector<vector<int>>dp;
public:

    DPGrid(vector<vector<int>>&matrix){
        int n = matrix.size(),m = matrix[0].size();
        mat = matrix;
        dp.resize(n,vector<int>(m,-1));
    }
    // Memoization
    int maximumPathSumUtil(int r,int c){
        if(r<0 or c<0 or r==mat.size() or c==mat[0].size())
            return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans=0;
        for(int op=-1;op<=1;op++){
            ans = max(ans,maximumPathSumUtil(r-1,c+op));
        }
        return dp[r][c] = mat[r][c]+ans;
    }

    // Tabulation
    int maximumPathSumUtil2(int r,int c){
        for(int i=0;i<c;i++)
            dp[0][i] = grid[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<c;j++){
                int maxi = mat[i-1][j];
                if(j!=0) maxi = max(maxi,mat[i-1][j-1]);
                if(j+1!=c)maxi = max(maxi,mat[i-1][j+1]);
                dp[i][j] = mat[i][j]+maxi;
            }
        }
        return *max_element(dp[r-1].begin(),dp[r-1].end());
    }
    int maximumPathSum(){
        int ans=0,r = mat.size(),c = mat[0].size();
        // for(int i=0;i<mat[0].size();i++){
        //     ans = max(ans,maximumPathSumUtil(mat.size()-1,i));
        // }
        return maximumPathSumUtil2(r,c);
    }
};  

int main(){

    return 0;
}
 