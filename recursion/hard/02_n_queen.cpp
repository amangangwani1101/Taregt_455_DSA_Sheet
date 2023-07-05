class BackTrack{
private:
    vector<vector<string>>ans;
    vector<int>col;
    vector<string>queenPos; 
    map<pair<int,int>,bool>mp;
    int sz;
public:
    BackTrack(int n){
        string temp;
        for(int i=0;i<n;i++)
            temp+='.';
        for(int i=0;i<n;i++)
            queenPos.push_back(temp);
        col.resize(n+1,0);
        sz = n;
    }

    bool isSafe(int n,int m){
        if(col[m])
            return false;
        int q =n,p = m;
        while(n>0 and m>0){
            if(queenPos[n-1][m-1]=='Q') return false;
            n-=1;m-=1;
        }
        while(q>0 and p<=sz){
            if(queenPos[q-1][p-1]=='Q') return false;
            q-=1;p+=1;
        }
        return true;
    }

    void f(int n,int idx){
        if(idx==n+1){
            ans.push_back(queenPos);
        }

        for(int t=1;t<=n;t++){
            if(!isSafe(idx,t)) continue;
            col[t]++;
            queenPos[idx-1][t-1] = 'Q'; 
            f(n,idx+1);
            col[t]--;
            queenPos[idx-1][t-1] = '.'; 

        }
    }

    vector<vector<string>> retAns(){
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        BackTrack bt(n);
        bt.f(n,1);
        return bt.retAns(); 
    }
};