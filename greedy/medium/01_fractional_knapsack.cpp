#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};
int fractionalKnapsack(int n,Item arr[],int W){
    sort(arr.begin(),arr.end(),[&](Item a,Item b){
        double first = (a.value*1.0)/a.weight;
        double second = (b.value*1.0)/b.weight;
        return first>second;
    });
    double cost=0;
    for(int i=0;i<n;i++){
        if(W>=arr[i].weight){
            W-=arr[i].weight;
            cost+=arr[i].value;
        }
        else{
            cost+=((arr[i].value*1.0*W)/arr[i].weight);
            break;
        }
    }
    return cost;
}