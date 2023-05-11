// Problem Link :https://leetcode.com/problems/majority-element-ii/description/

// 2 variation :  moore vote s' algorithm

// variation 1 ----> find element which is present more than n/2 time in an array

// variation 2 ----> find element which is present more than n/3 time in an array


#include<bits/stdc++.h>
using namespace std;


// approach used is moore voting algorithm which states try to find possible candidate 

// --> for variation 1 : element frequency is more than n/2 means if 
// n = 9 then el freq: 9/2+1 = 5 so only 1 candidate is possible for this variation

// --> for variation 2 : element frequency is more than n/3 means if 
// n = 10 then el freq: 10/3+1 = 4 so at max 2 candidate is possible for this variation

// strategy for variation 1 : declare 2 variables cand : for storing possible candidate element  and for keeping track of candidate we use cnt which is initially = 0 , now as candidate element frequncy is more than n/2 so overall it will be saved in cand 

// example : [1,2,2,2,1,1,1]
// cand = 1 , cnt = 1 at --- 1
// cand = 1 , cnt = 0 at --- 2
// cand = 2 , cnt = 1 at --- 3
// cand = 2 , cnt = 2 at --- 4
// cand = 2 , cnt = 1 at --- 5
// cand = 2 , cnt = 0 at --- 6
// cand = 1 , cnt = 1 at --- 7

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // variation 1
    
    int cand=arr[0],cnt=0;
    for(int i=0;i<n;i++){
        if(!cnt){
            cand = arr[i];
            cnt=1;
        }
        else if(cand!=arr[i]) cnt--;
        else cnt++;
    }    

    // double check if possible candidate is answer or not
    cnt=0;
    for(int i=0;i<n;i++)
        cnt+=(arr[i]==cand);
    cout<<(cnt>n/2?cand:-1)<<endl;

    // variation 2 

    int cand1 = -1,cand2 = -1,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        // to check if cand1 is empty and if arr[i] == cand2 then arr[i] is more important for cnt2 of cand2 
        if(!cnt1 and arr[i]!=cand2)
        {
            cand1 = arr[i];
            cnt1=1;
        }

        // to check if cand2 is empty and if arr[i] == cand1 then arr[i] is more important for cnt1 of cand1 
        else if(!cnt2 and arr[i]!=cnt1){
            cnt2=1;
            cand2 = arr[i];
        }
        else if(cand1==arr[i]) cnt1++;
        else if(cand2==arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    // check possible candidate is answer or not
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        cnt1+=(arr[i]==cand1);
        cnt2+=(arr[i]==cand2);
    }
    if(cnt1>n/3) cout<<cand1<<" ";
    if(cnt2>n/3) cout<<cand2<<" ";

    return 0;
}