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

    // for this question observe for each even row start from 0 and move alternatively while for odd row its starting from even

    for(int i=1;i<=n;i++){
        int start = (i&1)?1:0;
        for(int j=1;j<=i;j++){
            cout<<(start);
            start = 1- start;
        }
        cout<<endl;
    }
    return 0;
}


// output : 
// 1
// 01
// 101
// 0101
// 10101
