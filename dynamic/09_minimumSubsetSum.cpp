// minimum subset sum diff using tabulation method
// 
#include<iostream>
#include<vector>
using namespace std;
int minimimSubsetSum(vector<int> arr, int sum){

    // creating an table
    vector<vector<int>> table(arr.size()+ 1, vector<int>(sum+1));
    // initlizaing the table
    for(int i=0; i<arr.size()+1; i++) table[i][0] = true;
    for(int i=1; i<sum+1; i++) table[0][i] = false;

    // filling the table
    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                // either selecting or not selecting
                table[i][j] = table[i-1][j-arr[i-1]] || table[i-1][j];
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }
    
    // printing the table
    for(int i=0; i<arr.size()+1; i++){
        for(int j=0; j<sum+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return table[arr.size()][sum];
}


int main(){
    vector<int> arr = {1, 6, 11, 5};
    int k = 1;
    // let suppose an subset sum x and y then x + y = total_sum
    // here abs(x - y) = 1
    // it means one is odd and another one is even
    // so here ((total + 1) / 2) = y; 
    // soo here we have to find that is y is possible

    int total_sum = 0;
    for(int i=0; i<arr.size(); i++){
        total_sum+=arr[i];
    }

    int sum = ((total_sum + k) / 2);
    int ans = minimimSubsetSum(arr, sum);
    cout<<ans<<endl;
    return 0;
}   