// finding the smallest kth element of an array
// or
// finding the smallest k element of an array

// In heap it is not gaurtee that it is in sorted order
// the top most element is either min or max until now
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int getKthSmallestElement(vector<int> arr, int k){
    priority_queue<int> maxHeap;

    int i=0;
    while(i < arr.size()){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) maxHeap.pop();
        i++;
    }

    return maxHeap.top();
}

int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    // sort it in ascending order -> { 3, 4, 7, 10, 15, 20 }
    // output will be 7
    int k = 3;
    int ans = getKthSmallestElement(arr, k);
    cout<<ans<<endl;
    return 0;
}