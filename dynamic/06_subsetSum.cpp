// knapsack problem identification:
// 1. subset sum problem
// 2. equal sum partition
// 3. count of subset sum
// 4. minimum subset sum
// 5. target sum
// 6. no of subset sum with given diff

// subset sum problem using top-down problem
// 
#include<iostream>
#include<vector>
using namespace std;
bool subsetSum(vector<int> sum, int W){

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
    vector<int> sum = {2, 3, 7, 8, 10};
    int W = 11;
    bool ans = subsetSum(sum, W);
    cout<<ans<<endl;
    return 0;
}