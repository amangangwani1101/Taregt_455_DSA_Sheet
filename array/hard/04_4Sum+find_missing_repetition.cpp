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

