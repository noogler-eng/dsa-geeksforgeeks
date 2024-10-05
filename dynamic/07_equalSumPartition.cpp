// equal sum partition using tabulation method
// simillar problem of like 0/1 knapsack
#include<iostream>
#include<vector>
using namespace std;
// function is used to find if the subset is exists or not
bool EqualSumPartition(vector<int> sum, int W){
    vector<vector<bool>> table(sum.size()+1, vector<bool>(W+1));
    // initlizing the table
    for(int j=0; j<W+1; j++) table[0][j] = false;
    for(int i=0; i<sum.size()+1; i++) table[i][0] = true;

    // filling the table
    // max, min converts into true or false
    for(int i=1; i<sum.size()+1; i++){
        for(int j=0; j<W+1; j++){
            if(sum[i-1] <= j){
                table[i][j] = table[i-1][j-sum[i-1]] || table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    // printing the table
    for(int i=0; i<sum.size()+1; i++){
        for(int j=0; j<W+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[sum.size()][W];
}

int main(){
    vector<int> arr = {1, 2, 4, 1, 8};
    int sum, partition;
    for(int i=0; i<arr.size(); i++) sum+=arr[i];

    if(sum%2 == 0) {
        // no equal partition is possible
        cout<<0<<endl;
        return;
    }
    
    // if half of the sum exists then surely the array can be equally partioned
    partition = sum / 2;
    bool ans = EqualSumPartition(arr, partition);
    cout<<ans<<endl;
    return 0;
}