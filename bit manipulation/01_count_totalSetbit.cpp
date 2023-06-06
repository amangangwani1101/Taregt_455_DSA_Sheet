// Problem Link : https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include<bits/stdc++.h>
using namespace std;


int maxPower2(int n){
    return (int)log2(n);
}

int countTotalBits(int n){
    if(!n) return 0;
    int pow2 = maxPower2(n);
    return pow2*(1<<(pow2-1)) + n - (1<<(pow2))+1 + countTotalBits(n-(1<<(pow2))); 
}
int main(){

    return 0;
}