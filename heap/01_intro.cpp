// Heap and its introduction
// Heap 

// identification - when both comes together 
// - k is given
// - smallest or largest

// which heap to choose - 
// 1. k + smallest -> max heap (top most is maxi element)
// 2. k + largest -> min heap (top most is mini element)

// here the time complexity for kth largest element is nlogk 
// if we want to solve it using sorting then time compelxity is nlogn
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// it always gives us the min at top
// always default heap is max heap
int getKthLargestElement(vector<int> arr, int k){
    // min heap
    priority_queue <int, vector<int>, greater<int>> heap; 

    int i=0;
    while(i < arr.size()){
        heap.push(arr[i]);
        if(heap.size() > k) heap.pop();
        i++;
    }

    return heap.top();
}
int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    // sort it in ascending order -> { 3, 4, 7, 10, 15, 20 }
    // output will be 10
    int k = 3;
    int ans = getKthLargestElement(arr, k);
    cout<<ans<<endl;
    return 0;
} 