class DisjointSet{
private:
    vector<int>parent;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int nodeA,int nodeB){
        int ulp_a = findPar(nodeA);
        int ulp_b = findPar(nodeB);
        parent[ulp_a] = ulp_b;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>accountMerge;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(accountMerge.find(accounts[i][j])!=accountMerge.end()){
                    ds.Union(i,accountMerge[accounts[i][j]]);
                }
                else
                    accountMerge[accounts[i][j]] = i;
                // cout<<accounts[i][j]<<" ";
            }
        }

        // vector<pair<string,set<string>>>newAccount(n);

        // for(int i=0;i<n;i++){
        //     set<string>emailStore;
        //     for(int j=1;j<accounts[i].size();j++){
        //         emailStore.insert(accounts[i][j]);
        //     }
        //     if(newAccount[ds.findPar(i)].first==""){
        //         newAccount[ds.findPar(i)] = {accounts[ds.findPar(i)][0],emailStore};
        //     }
        //     else{
        //         newAccount[ds.findPar(i)].second.insert(emailStore.begin(),emailStore.end());
        //     }
        // }

        vector<vector<string>>finalEmail(n);

        for(auto it:accountMerge){
            int ulp = ds.findPar(it.second);
            finalEmail[ulp].push_back(it.first);
        }

        vector<vector<string>>finalMergeAccount;
        for(int i=0;i<n;i++){
            if(finalEmail[i].size()){
                sort(finalEmail[i].begin(),finalEmail[i].end());
                finalEmail[i].insert(finalEmail[i].begin(),accounts[i][0]);
                finalMergeAccount.push_back(finalEmail[i]);
            }
        }

        return finalMergeAccount;
    }
};