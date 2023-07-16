#include<bits/stdc++.h>
using namespace std;

class Slide{
private:
public:
    int f(string &s,int k){
        int n = s.size();
        int i=0,j=0;
        vector<int>freq(26,0);
        while(i<n){
            freq[s[i]-'A']++;
            while(i-j+1-(*max_element(freq.begin(),freq.end()))>k){
                freq[s[j]-'A']--;
                j++;
            }
            ans = max(ans,i-j+1);
            j++;
        }
        return ans;
    }
};
int main(){

    return 0;
}