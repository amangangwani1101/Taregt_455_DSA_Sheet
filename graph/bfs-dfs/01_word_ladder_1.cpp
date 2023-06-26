#include<bits/stdc++.h>
using namespace std;

class Question{
private:
    vector<int>alphabets;
    unordered_map<string,bool>saveWords;
    string start,target;
    unordered_set<string>word;
    queue<vector<string>>q;
    vector<vector<string>>ans;
public:
    Question(vector<string>&wordList,string startWord,string endWord){
        alphabets.resize(26,0);
        for(string temp:wordList){
            saveWords[temp] = true;
        }
        start = startWord;
        target = endWord;
    }
    
    vector<vector<string>> shortestPath(){
        q.push({start});
        saveWords[start] = false;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto temp = q.front();
                string last = temp.back();
                // cout<<last<<" ";
                q.pop();
                for(int s=0;s<last.size();s++){
                    char ch = last[s];
                    for(char al='a';al<='z';al++){
                        if(ch==al) continue;
                        last[s] = al;
                        if(saveWords[last]){
                            temp.push_back(last);
                            q.push(temp);
                            if(last==target){
                                ans.push_back(temp);
                            }
                            temp.pop_back();
                            word.insert(last);
                        }
                    }
                    last[s] = ch;
                }
            }
            for(string t:word)
                saveWords[t] = false;
            word.clear();
            if(ans.size()) break;
        }
        return ans;
    }
};
    

int main(){
    
    return 0;
}