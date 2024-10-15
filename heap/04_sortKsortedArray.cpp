// important
// sort a k sorted array || nearly sorted array sort
#include<iostream> 
#include<queue>
#include<vector>
using namespace std;
vector<int> kLargestElement(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;

    // time compleity is o(nlogk)
    // the min will not come from outside of range k thats why it is nearly sorted
    for(int i=0; i<arr.size(); i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k+1){
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while(minHeap.size() > 0){
        v.push_back(minHeap.top());
        minHeap.pop();
    }

    return v;
}
int main(){
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> ans = kLargestElement(arr, k);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}