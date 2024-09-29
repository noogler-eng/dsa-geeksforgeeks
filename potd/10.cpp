// there is N towers is giving 
// we have to performe an operation eith by increste the number by K or decrese it by K
// we have to finf the minimum possible diff after thr modification to each tower

// the array should not contains negative anytime
// k is givem

// input: k=2, n=4, arr[]={1, 5, 8, 10};
// modified, arr[]={3, 7, 6, 8}

#include<iostream>
// #include <bits/stdc++.h> 
#include<vector>
using namespace std;
int getMinFromModifiedArr(vector<int> &arr, int k){
    // i think greedy approach is best
    sort(arr.begin(), arr.end());
    int n = arr.size()-1;
    int ans = arr[n] - arr[0];

    int smallest = arr[0] + k;
    int largets = arr[n-1] - k;

    int mini, maxi;
    for(int i=0; i<n; i++){
        mini = min(smallest, arr[i+1] - k);
        maxi = max(largets, arr[i] + k);

        if(mini < 0) continue;
        // ans = Math.min(maxi-mini);
    }   
    return mini;
}

int main(){
    vector<int> arr = {1, 5, 8, 10};
    int k =2;
    int minDiff = getMinFromModifiedArr(arr, k);
    cout<<endl;
}