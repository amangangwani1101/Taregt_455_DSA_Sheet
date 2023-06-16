#include<bits/stdc++.h>
uisng namespace std;


class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    bool dfs(vector<vector<char>>&board,int r,int c,string s){
        if(!s.size()) return true;
        char ch = s[0];
        if(r<0 or c<0 or r==board.size() or c==board[0].size() or board[r][c]!=ch)
            return false;
        board[r][c] = '#';
        bool ans = false;
        for(int k=0;k<4;k++){
            int nr = r + dir[k];
            int nc = c + dir[k+1];
            ans |=dfs(board,nr,nc,s.substr(1));
        }
        board[r][c] = ch;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,i,j,word))
                    return true;
                }
            }
            return false;
        }
};

int main(){

    return 0;
}