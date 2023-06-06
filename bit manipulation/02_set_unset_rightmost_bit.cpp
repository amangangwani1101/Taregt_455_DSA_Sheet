
#include<bits/stdc++.h>
using namespace std;


// set first unset bit
int setBit(int N)
{
    // Write Your Code here
    // try to think how to convert this question into how to make 1st 0 bit as 1
    // given number : 1001 | (1111) = 0110
    int len = (int)log2(N) + 1;
    int num = (N ^((1<<len)-1));
    if(!num) return N;
    // simple code how to unset first set bit
    // 1001 + (0110)&(1010) = 1001 + 10  = 1011  
    return N + (num&(-num));   
}
// better code 

int setBir(int N){
    return (N&(N+1)?0:(N|(N+1)));
}

// unset first set bit
int unsetBit(int N){
    if(!N) return 0;
    return (N&(-N));
}


int main(){

    return 0;
}