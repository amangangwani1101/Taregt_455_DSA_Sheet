// Code Link :- https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-left-rotation


// Question Name : Quick Left Roatation

// given an array , left rotate array by k index int one pass 
// example :- [1,2,3,4,5,6,7] k = 10 or 3(10%7)
// 4 5 6 7 1 2 3

// intution : AB => ArB => ArBr => BA 
// where Ar : reverse of Ar array | Br : reverse of Br array
// 3 2 1 | 4 5 6 7  => 3 2 1 | 7 6 5 4 => 4 5 6 7 1 2 3
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return;
}
int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    
    int n = 7;
    int arr[] = {1,2,3,4,5,6,7,8};
    int k;cin>>k;
    k = k%n; // for exact shifts 
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
