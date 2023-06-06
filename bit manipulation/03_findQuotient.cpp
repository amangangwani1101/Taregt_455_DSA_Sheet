//  Problem Link : https://leetcode.com/problems/divide-two-integers/

#include<bits/stdc++.h>
using namespace std;

// intution : when you divide divsor with dividend then (quotient*divisor) + remainder = dividened using shift operators
// left shift operator work as multiplying by 2
// right shift operator work as dividing by 2

int findQuotient(long long int dividend,long long int divisor){

    bool isNeg = false;
    if((dividend<0 and divisor>0) or (dividend>0 and divisor<0))
        isNeg = true;

    divisor = abs(divisor);
    dividend = abs(dividend);

    long long int ans=0;
    while(dividend>=divisor){
        long long int temp = divisor,qu=1;
        while(temp<=dividend){
            temp=temp<<1;
            qu=qu<<1;
        }
        ans+=(qu>>1);
        dividend -=(temp>>1);
    }

    if(isNeg)
        return max((~ans) + 1,1ll*INT_MIN);
    return min(ans,1ll*INT_MAX);

}

int main(){

    return 0;
}