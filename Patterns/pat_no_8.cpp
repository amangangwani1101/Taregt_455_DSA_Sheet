#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        // inner loop-1 for spaces
        for(int j=1;j<i;j++)
            cout<<" ";
        
        // innner loop for stars
        for(int j=1;j<=(2*n-2*i+1);j++)
            cout<<"*";
        
        cout<<endl;
    }
    return 0;
}

// Output 
// *********
//  *******
//   *****
//    ***
//     *
