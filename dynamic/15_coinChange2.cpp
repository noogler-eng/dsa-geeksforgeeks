// coin change problem 2
// solved using dp tabulation method
#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;
int coinChangeMinCoins(vector<int> coins, int sum){

    // INT_MAX is biggest value so INT_MAX + 1 will be out of reach so that why INT_MAX - 1
    vector<vector<int>> table(coins.size()+1, vector<int>(sum+1, INT_MAX-1));
    for(int i=0; i<coins.size()+1; i++) table[i][0] = 0;
    for(int j=1; j<sum+1; j++) table[0][j] = INT_MAX;

    // filling thr table
    // minimum count is asking so + and min is used
    for(int i=1; i<coins.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coins[i-1] <= j){
                table[i][j] = min(1 + table[i][j-coins[i-1]], table[i-1][j]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    for(int i=0; i<coins.size()+1; i++){
        for(int j=0; j<sum+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[coins.size()][sum];
}

int main(){
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    int ans = coinChangeMinCoins(coins, sum);
    cout<<ans<<endl;
    return 0;
}