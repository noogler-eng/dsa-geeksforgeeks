// memoization of recursive code
// knapsack
#include<iostream>
using namespace std;

// 0.memoization
// 1. matrix is always formed of that which are changing, like index and W
// 2. 
int knapsack(vector<int> arr, vector<int> val, int W, int index, vector<vector<int>> store){
    if(index == 0 || W == 0) return 0;

    if(store[index-1][W] != -1) return store[index][W];
    
    if(arr[index-1] <= W){
        // either select or not selecting
        return store[index-1][W] = max(knapsack(arr, val, W-arr[index-1], index+1, store) + val[index-1], knapsack(arr, val, W, index+1, store));
    }else{
        // not selecing
        return store[index][W] = knapsack(arr, val, index+1, W, store);
    }    
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<int> val = {10, 15, 40};
    int W = 7;

    vector<vector<int>> store(arr.size(), vector<int>(W+1, -1));
    int ans = knapsack(arr, val, W, arr.size(), store);
    cout<<ans<<endl;
    return 0;
}