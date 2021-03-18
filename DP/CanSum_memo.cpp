#include<bits/stdc++.h>
using namespace std;

bool memo[1000000]={false};

bool makeSum(int targetSum,int coins[],int n) {
    if(memo[targetSum] == true)
        return true;
    if(targetSum == 0)
        return true;
        
    for(int i=0;i<n;i++){
        if(coins[i] <= targetSum){
             if(makeSum(targetSum-coins[i],coins,n)){
                memo[targetSum-coins[i]] = true;
                return true;
             }
        }
    }
    
    memo[targetSum] = false;
    return false;
}

int main() {
    int n = 1,targetSum = 1000;
    int coins[n] = {7} ;
    cout<<makeSum(targetSum,coins,n)<<endl;
    return 0;
}