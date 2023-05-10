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

    // based on concept of distabce of a element from all 4 direction and minimum of them is anwer like for example element at r=0,c=0;
    // from left {i}0 | right {2*n-i-2}6 | up {j}0 | down {2*n-j-2}6
      
    for(int i=0;i<(2*n-1);i++){
        for(int j=0;j<(2*n-1);j++){
            cout<<n-min({i,j,2*n-i-2,2*n-j-2});
        }
        cout<<endl;
    }
    return 0;
}


// output : 
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
