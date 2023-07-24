#incldue<bits/stc++.h>
using namespace std;


struct Job{
    int id;
    int dead;
    int profit;
};

class Solution {
    // method 1 :: greedy O(N2)
    int maxProfit(Job arr[],int n){
        sort(arr,arr+n,[&](Job a,Job b){
            return a.profit>b.profit;
        });
        int ans=0;
        vector<int>deadline(n+1,-1);
        for(int i=0;i<n;i++){
            int currentDead = arr[i].dead;
            while(currentDead>=1){
                if(deadline[currentDead]!=-1){
                    ans+=arr[i].profit;
                    dedline[currentDead] = i;
                    break;
                }
                currentDead--;
            }
        }    
        return ans;
    }

    // method 2 :: priority queue
    int maxProfit2(Job arr[],int n){
        sort(arr,arr+n,[&](Job a,Job b){
            return a.dead<b.dead;
        });
        int ans=0;
        priority_queue<int,vector<int>>pq;
        int cnt=1;
        for(int i=n-1;i>=0;i--){
            if(!pq.empty() or pq.top()==arr[i].dead){
                pq.push(arr[i].profit);
            }
            else{
                cnt++;
                ans+=pq.top();
                pq.pop();
            }
        }
        ans+=pq.top();
        return {cnt,ans};
    }
};
int main(){
    return 0;
}