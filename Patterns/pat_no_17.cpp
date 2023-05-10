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
        // space
        for(int j=i;j<n;j++)
            cout<<" ";
        
        // alphabet :- increasing
        for(int j=1;j<=i;j++)
            cout<<char('A'+j-1);
        
        // alphabet :- decreasing
        for(int j=i-1;j>=1;j--)
            cout<<char('A'+j-1);

        cout<<endl;
    }
    return 0;
}


// output : 
//     A
//    ABA
//   ABCBA
//  ABCDCBA

