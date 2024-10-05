// Knapsack problem using top down approach
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> weight, vector<int> value, int W){
    // here for j = 0; the W = 0
    // so items we can take of value = 0;
    vector<vector<int>> table(weight.size()+1, vector<int>(W+1));
    for(int i=0; i<weight.size()+1; i++) table[i][0] = 0;
    // here we have no item in the bag means size of weight arr is 0
    for(int j=0; j<W+1; j++) table[0][j] = 0;

    
    for(int i=1; i<weight.size()+1; i++){
        for(int j=1; j<W+1; j++){
            // here j is the current Max wight
            if(weight[i-1] <= j){
                table[i][j] = max(value[i-1] + table[i-1][j-weight[i-1]], table[i-1][j]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    // printing tha table
    for(int i=0; i<table.size(); i++){
        for(int j=0; j<table[0].size(); j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[weight.size()][W];
}

int main(){
    // not need to be in sorted way
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;

    int ans = maxProfit(weight, value, W);
    cout<<ans<<endl;
    return 0;
}


// 1. identifying method -> tabulation
// 2. initlized the table with size+1 matrix -> 1D, 2D, initlization in 1st row and 1st col
// 3. find out the loop with indexes starting 
// 5. try ways like max, sum, min, ...
// 6. returning the last row, col block of matrix