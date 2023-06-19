#include<bits/stdc++.h>
using namespace  std;

class Question{
private:
    vector<int>adj[26];
    vector<int>indegree;
    string ans="";
public:
    void buildGraph(string dict[],int n,int k){
        
        indegree.resize(k+1,0);
        for(int i=1;i<n;i++){
            string s = dict[i-1],t = dict[i];
            int j=0,k=0;
            while(j<s.size() and k<t.size()){
                if(s[j]!=t[k]){
                    adj[s[j]-'a'].push_back(t[k]-'a');
                    indegree[t[k]-'a']++;
                    break;
                }
                j++;k++;
            }
        }
    }
    string dictOrder(int k){
        queue<int>q;
        for(int i=0;i<k;i++){
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=('a'+node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
    return ans;
    }
};
int main(){
    return 0;
}