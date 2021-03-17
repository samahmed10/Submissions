#include<bits/stdc++.h>
using namespace std;

bool makeSum(int targetSum,int coins[],int n) {
    if(targetSum == 0)
        return true;
    for(int i=0;i<n;i++)
        if(coins[i] <= targetSum)
             if(makeSum(targetSum-coins[i],coins,n))
                return true;
    return false;
}
int main() {
    int n,targetSum;
    int coins[n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>coins[i];
    cin>>targetSum;
    cout<<makeSum(targetSum,coins,n);
    return 0;
}