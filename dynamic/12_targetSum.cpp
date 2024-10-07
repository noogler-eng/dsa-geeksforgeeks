// target sum by tabulation db
// we have to sign the +, - to front of each number, then if we get the
// number then count it
#include<iostream>
#include<vector>
using namespace std;
int countTargetSum(vector<int> arr, int sum){

    vector<vector<int>> table(arr.size()+1, vector<int>(sum+1));
    for(int i=0; i< arr.size()+1; i++) table[i][0] = 1;
    for(int i=1; i<sum+1; i++) table[1][i] = 0;

    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                table[i][j] = table[i-1][j-arr[i-1]] + table[i-1][j];
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

    return table[arr.size()][sum];
}



int main(){
    vector<int> arr = {1, 1, 2, 3};
    int sum = 1;
    // output = 3

    int total_weight = 0;
    for(int i=0; i<arr.size(); i++) total_weight += arr[i];

    // same as of previos question in which s1 - s2 = 1
    // both s1 and s2 are posiive so s1 > 0 and s2 > 0
    // here also s1 - s2 = sum;
    // here s1 + s2 = total_weight;
    // count s1 = s2 + sum;
    // s1 = (total_weight + sum) / 2;
    int ans = countTargetSum(arr, (total_weight + sum) / 2);
    cout<<ans<<endl;
    return 0;
}