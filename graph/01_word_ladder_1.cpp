#include<bits/stdc++.h>
using namespace std;

class Question{
private:
    vector<int>alphabets;
    unordered_map<string,bool>saveWords;
    string start,target;
    queue<string>q;
public:
    Question(vector<string>&wordList,string startWord,string endWord){
        alphabets.resize(26,0);
        for(string temp:wordList){
            saveWords[temp] = true;
        }
        start = startWord;
        target = endWord;
    }
    
    int shortestPath(){
        int time = 1;
        q.push(start);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string temp = q.front();
                q.pop();
                if(temp==target) return time;
                for(int s=0;s<temp.size();s++){
                    char ch = temp[s];
                    for(char al='a';al<='z';al++){
                        if(ch==al) continue;
                        temp[s] = al;
                        if(saveWords[temp]){
                            q.push(temp);
                            saveWords[temp] = false;
                        }
                    }
                    temp[s] = ch;
                }
            }
            time++;
        }
        return 0;
    }
};

int main(){
    
    return 0;
}