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

// better code 
int setBir(int N){
    return (N&(N+1)?0:(N|(N+1)));
}

// unset first set bit
int unsetBit(int N){
    if(!N) return 0;
    return (N&(-N));
}

// difference bit in 2 numbers
int diffBitNums(int num1,int num2){
    int xor_nums = num1^num2;
    int cnt=0;
    while(xor_nums>0){
        cnt++;
        xor_nums -=(xor_nums&(-xor_nums));
    }
    return cnt;
}

// power set or generate all subsets
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subset = pow(2,n);
    vector<vector<int>>ans;
    for(int i=0;i<subset;i++){
        vector<int>temp;
        for(int bit = n-1;bit>=0;bit--){
            int p = pow(2,bit);
            if(p&i)
                temp.push_back(nums[bit]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    
    return 0;
}