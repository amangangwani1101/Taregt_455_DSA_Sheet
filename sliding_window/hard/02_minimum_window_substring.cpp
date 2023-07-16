#include<bits/stdc++.h>
using namespace  std;

int f(string &s,string &t){
    int i=0,j=0;
    int n = s.size() , m = t.size();
    map<char,int>freq,freq2;
    for(int i=0;i<m;i++)
        freq[t[i]]++,freq2[t[i]]++;
    while(i<n){
        if(m>=0){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(!mp[s[i]])
                    m--;
            }
        }
        if(!m){
            ans = min(ans,i-j+1);
            while(i<=j and !m){
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                    if(mp[s[j]]==freq2[s[j]])
                        m++;
                }    
            }
        }
        i++;
    }
    return ans;
}
int main(){

    return 0;
}