// count of suset with given sum
// solving this problem using tabulation method
#include<iostream>
#include<vector>
using namespace std;
int countSubsetSum(vector<int> sum, int W){

    // creating table
    vector<vector<int>> table(sum.size()+1, vector<int>(W+1));
    // initlizing the table
    // when W = 0 then 1 subset is always possible that is of NULL
    for(int i=0; i<table.size(); i++) table[i][0] = 1;
    // when there is 0 elements then no subset is possible with givn W != 0
    for(int i=1; i<table[0].size(); i++) table[0][i] = 0;

    // filling the table data
    // finding the total subset possible
    for(int i=1; i<sum.size()+1; i++){
        for(int j=1; j<W+1; j++){
            if(sum[i-1] <= j){
                table[i][j] = table[i-1][j-sum[i-1]] + table[i-1][j];
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
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int W = 5;

    int ans = countSubsetSum(arr, W);
    cout<<ans<<endl;
    return 0;
}