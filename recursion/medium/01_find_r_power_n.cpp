#include<bits/stdc++.h>
#define ll long long 
using namespace std;

// find power(R,N) for large Number and to maintain overflow use 1e9+7

const int MOD = 1e9+7;
ll power(ll n,ll r){
    
    // r is odd
    if(r&1)
    {
        ll y = n%MOD;
        return (y*power(y,r-1)%MOD)%MOD;
    }
    ll y = (n*n)%MOD;
    return power(y,r/2)%MOD;
}

long long power(int N,int R)
{
    //Your code here
    long long ans = 1;
    long long n = 1ll*N;
    long long r = 1ll*R;
    while(r>0){
        if(r&1)
        ans = ((ans%MOD)*(n%MOD))%MOD,r-=1;
        else
        n=(n*n)%MOD,r/=2;
    }      
    return ans;
    
}

int main(){
    cout<<power(12,9)<<endl;
    return 0;
}