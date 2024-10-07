// minimum difference subset
#include<iostream>
#include<vector>
using namespace std;
int minimumSubsetDiff(vector<int> arr, int sum, int totalsum){
    
    // filtering if the subset is possible or not
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
    
    int s2 = -1;
    for(int i=totalsum / 2; i>=0; i--){
        // maximizing it
        if(table[arr.size()][i] == true){
            s2 = i;
            break;
        }
    }

    int s1 = abs(totalsum - s2);
    return s1 - s2;
}

int main(){
    vector<int> arr = {1, 2, 7};
    // here we should get the minimum abs diff abs(s1-s2)
    // here we know s1 + s2 = total_sum
    // so s1 + s1 - min = total_sum
    // s1 - s2 = min
    // 0 <= s1, s2 <= 23

    int total_sum = 0;
    for(int i=0; i<arr.size(); i++) total_sum += arr[i];
    // we only move towards the halfway

    int ans = minimumSubsetDiff(arr, total_sum / 2, total_sum);
    cout<<ans<<endl;
    return 0;
}