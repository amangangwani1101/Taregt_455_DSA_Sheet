#include<bits/stdc++.h>
using namespace std;

// logic lie in fact of finding pattern
//  number   bit-representation        result            decimal
//   1           001                    001                 1
//   2           010                    011                 3 
//   3           011                    000                 0
//   4           100                    100                 4
//   5           101                    001                 1
//   6           110                    111                 7  
//   7           111                    000                 0
//   8          1000                   1000                 8
//   9          1001                   0001                 1

// so we can see a pattern 
// 1 is repeated after every 4 numbers means if number % 4 = 1
// 0 is repeated after every 4 numbers means if number % 4 = 3
// number is repeated after every 4 numbers means if number % 4 = 0
// number+1 is repeated after every 4 numbers means if number % 4 = 2

// bruteForce
int findXor(int l,int r){
    int ans=0;
    for(int i=0;i<=30;i++){
        int p = 1<<i;
        int cnt=0;
        for(int start = l;start<=r;start++){
            if(p&start) cnt++;
        }
        if(cnt&1) ans+=p;
    }
    return ans;
}

// optimized approach
int findXorOptimizedUtil(int n){
    if(n%4==0) 
        return n;
    else if(n%4==1) 
        return 1;
    else if(n%4==2) 
        return n+1;
    else
        return 0;    
}
int findXorOptimized(int l,int r){
    return findXorOptimizedUtil(r) ^ findXorOptimizedUtil(l-1);
}
int main(){

    return 0;
}