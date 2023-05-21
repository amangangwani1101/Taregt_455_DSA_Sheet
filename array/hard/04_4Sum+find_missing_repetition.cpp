//  see better code + approach : Solved But Refer better code

// -->  4 Sum :- https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/

#include<bits/stdc++.h>
using namespace std;

// intution moves behind the fact of 3 sum problem just put one more outer loop for fixing 4th element 
int main(){
    int n;
    cin>>n;
    long long int tgt;
    cin>>tgt;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<int>>ans;
        // [1,1,1,2,2,2] tgt = 6
        sort(arr,arr+n);
        for(int i=0;i<n-3;i++){
            if(i!=0 and arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=(i+1) and arr[j]==arr[j-1]) continue;
                long long int curr_sum = 1ll*tgt - (1ll*arr[i] + 1ll*arr[j]);
                int l = j+1,r = n-1;
                while(l<r){
                    if(arr[l]+arr[r]==curr_sum){
                        vector<int>inst = {arr[i],arr[j],arr[l],arr[r]};
                        if(ans.empty() or ans.back()!=inst)
                            ans.push_back(inst);
                        l++;
                        r--;
                    }
                    else if(arr[l]+arr[r]<curr_sum){
                        l++;
                    }
                    else    
                        r--;
            }
        }
    }
    return 0;
}

// --> Find Repeating And Missing Number : -https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/

// [1,2,3,4,4]
// Missing Number :- 5
// Rrpeating Number :- 4

// Optiimized Way:- using xor operation 
// Step 1 : take xor of array with size of array means 1 2 3 4 5 1 2 3 4 4 = 4^5 = 0001(1)
// Step 2 : now try to divide xor answer into 2 sets on basis of divison of rightmost set bit 1 - (1 & ~1) = 0 

// Set 1 : 1  | Set 2 : 0
// now check whose bit are set for set 1 and for set 2
// Set 1 : 1^3  
// Set 2 : 2^4^4

// now checke with actual sets as n=5 so actual set : [1,2,3,4,5]
// Set 1 : 1^3^1^3^5 = 5 (missing number)
// Set 2 : 2^4^4^2^4 = 4 (repeating number)


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int xo=0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        xo = xo^arr[i];
        xo = xo^(i+1);
    }
    int set1 = xo&(-xo),set2=xo-set1;
    int rep = 0,miss=0;
    for(int i=0;i<n;i++){
        
        if(set1 & arr[i]){
            rep = rep^arr[i];
        }
        else
            miss = miss^arr[i];

        if((i+1) & set1){
            rep = rep^(i+1);
        }
        else
            miss = miss^(i+1);

    }
    for(int i=0;i<n;i++){
        if(miss==arr[i]) {swap(rep,miss);break;}
    }
    cout<<miss<<" "<<rep<<endl;
    return 0;
}