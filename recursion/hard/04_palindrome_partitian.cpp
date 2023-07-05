class BackTrack{
private:
    vector<int>dp;
public:
    BackTrack(int n){
        dp.resize(n,-1);
    }
    
    bool isPalindrome(string s){
        int i=0,j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    } 
    
    int palindromePartitian(string &str,int idx){
        if(idx==str.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int partitian = INT_MAX;
        string temp="";
        for(int i=idx;i<str.size();i++){
            temp+=str[i];
            if(!isPalindrome(temp)) continue;
            partitian = min(partitian,1 + palindromePartitian(str,i+1));
        }
        return dp[idx] = partitian;
    }
};
class Solution{
public:
    bool reverse2(string s){
        int i=0,j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        BackTrack bt(n);
        return bt.palindromePartitian(str,0)-1; 
        // code here
        int n = str.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                string ins = str.substr(j,i-j);
                if(dp[j]!=INT_MAX and reverse2(ins)){
                    if(j!=0)
                        dp[i]=min(dp[i],1 + dp[j]);
                    else
                        dp[i] = min(dp[i],dp[j]);
                }
            }
        }
        return dp[n];
    }
};
