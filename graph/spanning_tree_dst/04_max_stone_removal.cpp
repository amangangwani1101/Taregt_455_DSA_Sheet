
class DisjointSet{
private:
    vector<int>parent,rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void Union(int a,int b){
        int ulp_a = findPar(a);
        int ulp_b = findPar(b);
        if(ulp_a==ulp_b)
            return;
        if(rank[ulp_a]<rank[ulp_b]){
            parent[ulp_a] = ulp_b;
        }
        
        else if(rank[ulp_a]>rank[ulp_b]){
            parent[ulp_b] = ulp_a;
        }
        else{
            parent[ulp_a] = ulp_b;
            rank[ulp_b]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int r=0,c=0;
        for(int i=0;i<n;i++){
            r = max(r,stones[i][0]+1);
            c = max(c,stones[i][1]+1);
        }
        DisjointSet ds(r+c);
        for(int i=0;i<n;i++){
            int rr = stones[i][0];
            int cc = r+stones[i][1];
            ds.Union(rr,cc);
        }
        int cnt=0;
        vector<int>comp(r+c,0);
        for(int i=0;i<(r+c);i++){
            comp[ds.findPar(i)]++;
        }
        for(int i=0;i<r+c;i++){
            if(comp[i]>1)
                cnt++;
        }
        return n - cnt;
    }
};