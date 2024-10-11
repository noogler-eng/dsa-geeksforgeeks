// For base condition check always the smallest valid INPUT
// dp -> knapsack problem
#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int index){
    if(index == -1 || W == 0) return 0;

    if(wt[index] <= W){
        // when weight is less then either we can add or not add
        return max(knapsack(W-wt[index], wt, val, index-1) + val[index], knapsack(W, wt, val, index-1));
    }else{
        // if the weight > then required then not add
        return knapsack(W, wt, val, index-1);
    }
}

int main(){
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};

    int W = 7;
    int ans = knapsack(W, wt, val, wt.size()-1);
    cout<<ans<<endl;
    return 0;
}