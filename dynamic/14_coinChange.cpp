// coin change problem using dp tabulation
#include<iostream>
#include<vector>
using namespace std;

// we have to find the minimum no of ways
int coinChange(vector<int> arr, int sum){

    // creating the table and initilzing it
    vector<vector<int>> table(arr.size()+1, vector<int>(sum+1));
    // i have a 1 way that i filled nothing
    for(int i=0; i<arr.size()+1; i++) table[i][0] = 1;
    // i have 0 ways for this as i dont have any coins
    for(int i=1; i<sum+1; i++) table[0][i] = 0;

    // filling of the table
    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = table[i][j-arr[i-1]] + table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    for(int i=0; i<arr.size()+1; i++){
        for(int j=0; j<sum+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    // returning the minimum no of coins to reach sum = given_sum
    return table[arr.size()][sum];
}

int main(){
    vector<int> arr = {1, 2, 3};
    // 2 + 3 = 5
    // 1 .... = 5
    // 1 + 2 + 2 = 5
    // 1 + 1 + 3 = 5
    // 1 + 1 + 1 + 2 = 5 
    // total 5 ways
    int sum = 5;
    int ans = coinChange(arr, sum);
    cout<<ans<<endl;
    return 0;
}