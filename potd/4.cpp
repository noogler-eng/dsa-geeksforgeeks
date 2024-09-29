#include<iostream>
#include<queue>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;
// minimum cost of ropes
// cost of connecting to ropes is sum of their length
// input: [4, 3, 2, 6]
// output: 29

// [4, 3, 2, 6]
// sorting for greddy approach
// then connecting one by one with adding their sum in total cost

int minCost(vector<int> &arr){
    
    // this always gives us the minimum element in the stack present
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // sorting by min heap
    for(int i=0; i<arr.size(); i++){
        minHeap.push(arr[i]);
    }

    // connecintg 
    // connecting minimum first as a greedy approach
    // connect two of the possible ropes at every steps
    // we have to selec the data structure which will always gives minimum element at top
    int cost = 0, sum = 0;
    for(int i=1; i<arr.size(); i++){
        int firstMin = minHeap.top();
        minHeap.pop();
        int secondMin = minHeap.top();
        minHeap.pop();
        sum = firstMin + secondMin;
        minHeap.push(sum);
        cost+=sum;
    }
    return cost;
}


int main(){
    vector<int> arr_1 = {3, 5, 4}; 
    // output = 19
    vector<int> arr_2 = {4, 3, 2, 6};
    // output = 29
    int ans_1 = minCost(arr_1);
    cout<<ans_1<<endl;
    int ans_2 = minCost(arr_2);
    cout<<ans_2<<endl;
    return 0;
}