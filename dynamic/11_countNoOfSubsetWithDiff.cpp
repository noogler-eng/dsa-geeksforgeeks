#include<iostream>
#include<vector>
using namespace std;

int countSubsetWithGivenDiff(vector<int> arr, int sum){
     
    vector<vector<int>> table(arr.size()+1, vector<int>(sum+1));
    for(int i=0; i<arr.size()+1; i++) table[i][0] = 1;
    // here we have no item in the bag means size of weight arr is 0
    for(int j=1; j<sum+1; j++) table[0][j] = 0;

    
    for(int i=1; i<arr.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            // here j is the current Max wight
            if(arr[i-1] <= j){
                table[i][j] = table[i-1][j-arr[i-1]] + table[i-1][j];
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

    return table[arr.size()][sum];
}

int main(){
    vector<int> arr = {1, 1, 2, 3};
    int k = 1;
    // s1, s2 then there is diff like abs(s1 - s2) = k
    // s1 = s2 + k;
    // s1 + s2 = total_sum
    // s1 - s2 = k;
    // adding both then we get s1 = (k + totla_sum )/2;
    // if subset with this given sum exists then count;

    int total_diff = 0;
    for(int i=0; i<arr.size(); i++) total_diff+=arr[i];
 
    int ans = countSubsetWithGivenDiff(arr, (total_diff + k) / 2);
    cout<<ans<<endl;
    return 0;
}