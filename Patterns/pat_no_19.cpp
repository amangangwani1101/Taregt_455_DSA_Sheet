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

    for(int i=1;i<=(2*n);i++){
        if(i<=n){
            // stars
            for(int j=i;j<=n;j++)
                cout<<"*";
            
            // spaces 
            for(int k=1;k<=(2*i-2);k++)
                cout<<" ";
            
            // stars
            for(int j=i;j<=n;j++)
                cout<<"*";
        }
        else{
            // stars
            for(int j=1;j<=(i-n);j++)
                cout<<"*";
            
            // spaces 
            for(int k=1;k<=(2*n-2*(i-n));k++)
                cout<<" ";
            
            // stars
            for(int j=1;j<=(i-n);j++)
                cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}


// output : 
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
