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

// optimized approach : 
class Question{
private:
    map<int,map<string,bool>>mp;
    unordered_map<string,bool>saveWord;
    vector<int>alphabet;
    string start,end;
    queue<string>q;
    vector<vector<string>>ans;
public:
    Question(string startWord,string endWord,vector<string>&wordList){
        alphabet.resize(26,0);
        for(string word:wordList)
            saveWord[word] = true;
        start = startWord;
        end = endWord;
    }

    int shortestPath(){
        q.push(start);
        int t = -1;
        int time=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string temp = q.front();
                q.pop();
                mp[time][temp] = true;
                if(temp == end)
                    return time;
                for(int w=0;w<temp.size();w++){
                    char ch = temp[w];
                    for(char p='a';p<='z';p++){
                        temp[w] = p;
                        if(saveWord[temp]){
                            q.push(temp);
                            saveWord[temp] = false;
                        }
                    }
                    temp[w] = ch;
                }
            }
            time++;
        }
        return -1;
    }

    void pathStartEnd(int t,vector<string>&path){
        if(t<0){
            ans.push_back(path);
            return;
        }
        string temp = path.back();
        for(int w=0;w<temp.size();w++){
        char ch = temp[w];
        for(char p='a';p<='z';p++){
            temp[w] = p;
                if(mp[t][temp]){
                    path.push_back(temp);
                    pathStartEnd(t-1,path);
                    path.pop_back();
                }
            }
            temp[w] = ch;
        }
    }

    vector<vector<string>> getAns(){
        for(auto &it:ans){
            reverse(it.begin(),it.end());
        }
        return ans;
    }
};

int main(){
    return 0;
}