#include<bits/stdc++.h>
using namespace std;


class DP{
private:
    vector<int>height;
public:
    DP(vector<int>&h){
        height = h;
    }

    // Recursion : (2^N)
    int climbStairRec(int currStair,vector<int>&dp){
        
        if(currStair<=0) return 0;
        if(currStair<2) return abs(height[currStair] - height[currStair-1]);
        if(~dp[currStair]) return dp[currStair];
        int choice1 = abs(height[currStair]-height[currStair-1]) + climbStairRec(currStair-1,dp);
        int choice2 = abs(height[currStair]-height[currStair-2]) + climbStairRec(currStair-2,dp);
        return dp[currStair] = min(choice1,choice2); 
    }
    
    // Tabulation 
    int climbStairTab(int currStair,vector<int>&dp){
        if(currStair<2) return 0;
        dp[1] = abs(height[1]-height[0]);
        for(int idx=2;idx<currStair;idx++){
            int choice1 = abs(height[idx]-height[idx-1]) + dp[idx-1];
            int choice2 = abs(height[idx]-height[idx-2]) + dp[idx-2];
            dp[idx] = min(choice1,choice2);            
        }
        return dp[currStair-1];
    }
    
    // Tabulation + Space Optimization 
    int climbStairTab_Space(int currStair){
        if(currStair<2) return 0;
        int prev=0,curr= abs(height[1]-height[0]);
        for(int idx=2;idx<currStair;idx++){
            int choice1 = abs(height[idx]-height[idx-1]) + curr;
            int choice2 = abs(height[idx]-height[idx-2]) + prev;
            int next = min(choice1,choice2);            
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
int main(){

    return 0;
}