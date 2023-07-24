#include<bits/stdc++.h>
using namespace std;

class Sol{
private:
    vector<vector<int>>ans;
public:
    void bridges(vector<int>adj[],int node,int par,vector<int>&minimumBackSteps,vector<int>&currSteps,int cStep){
        vis[node] = 1;
        minimumBackSteps[node] = currSteps[node] = cStep++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(vis[it]){
                minimumBackSteps[node] = min(minimumBackSteps[node],minimumBackSteps[it]);
            }
            else{
                dfs(adj,it,node,minimumBackSteps,currSteps,cStep);
            }
        }
        if(par!=-1){
            minimumBackSteps[par] = min(minimumBackSteps[par],minimumBackSteps[node]);
            if(currSteps[par]>=minimumBackSteps[node]){
                ans.push_back({par,node});
            }
        }
        return;
    }
    vector<vector<int>> getAns()
        return ans;
};
int main(){
    return 0;
}