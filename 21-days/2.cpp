// Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and 
// arr[i] + arr[j] == 0.

// Note: The pairs must be returned in sorted order, the solution array should also be sorted, and
// the answer must not contain any duplicate pairs.

#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<vector<int>> getPairs(vector<int> &arr) {
    // condition i!=j
    // condition arr[i]!=arr[j]

    vector<vector<int>> ans;

    for(int i=0; i<arr.size()-1; i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] + arr[j] == 0 && i!=j){
                
                vector<int> short_ans;
                if(arr[i] < arr[j]){
                    short_ans.push_back(arr[i]);
                    short_ans.push_back(arr[j]);
                }else{
                    short_ans.push_back(arr[j]);
                    short_ans.push_back(arr[i]);
                }

                ans.push_back(short_ans);

                // so that arr[j] will not come again
                arr[j] = INT_MAX;
            }
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {4, 8, 4, 2, 0, -10, 7, 3, -7};
    vector<vector<int>> ans = getPairs(arr);

    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}   