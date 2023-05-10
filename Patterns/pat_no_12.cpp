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

    for(int i=1;i<n;i++){
        // digits  
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        
        // spaces
        for(int j=0;j<(2*(n-i)-2);j++){
            cout<<" ";
        }

        // digits 
        for(int k=i;k>=1;k--){
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}


// output : 
// 1      1
// 12    21
// 123  321
// 12344321
