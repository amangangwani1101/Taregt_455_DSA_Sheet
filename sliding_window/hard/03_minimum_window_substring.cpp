class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(256,0);
        int n = s.size();
        int m = t.size(),st=-1;
        int ans=n+1;
        for(int i=0;i<m;i++)
            freq[t[i]]++;
        int i=0,j=0;
        while(i<n){
            freq[s[i]]--;
            if(freq[s[i]]>=0){
                m--;
            }
            while(j<=i and !m){
                if(ans>(i-j+1)){
                    ans = i-j+1;
                    st = j;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0)
                    m++;
                j++;
            }
            i++;
        }
        return st==-1?"":s.substr(st,ans);
    }
};

class Solution {
public:
    bool isPoss(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
        for(auto it:mp1){
            if(mp2[it.first]<it.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>reqWindow,currWindow;
        int n = s.size() , m = t.size(),ans=n+1;
        int i=0,j=0,st=-1;
        for(int i=0;i<m;i++)
            reqWindow[t[i]]++;
        while(i<n){
            currWindow[s[i]]++;
            while(j<=i and isPoss(reqWindow,currWindow)){
                if(ans>(i-j+1)){
                    ans = i-j+1;
                    st = j;
                }
                currWindow[s[j]]--;
                j++;
            }
            i++;
        }
        return st==-1?"":s.substr(st,ans);
    }
};