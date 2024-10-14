#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> kLargestElement(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;

    // time compleity is o(nlogk)
    for(int i=0; i<arr.size(); i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    // time compelxity is o(k)
    while(minHeap.size() > 0){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
    
}
int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    vector<int> ans = kLargestElement(arr, k);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}