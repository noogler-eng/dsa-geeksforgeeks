// we have to find the k closet numbr of any given number from array
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> kClostestNumber(vector<int> arr, int k, int x){
    // decresing the k from all 
    for(int i=0; i<arr.size(); i++){
        arr[i] = arr[i] - x;
    }

    // using maxHeap to get the k smallest number;
    priority_queue<int> maxHeap;
    for(int i=0; i<arr.size(); i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }

    // we can also push the pair in heap pair<int, int>, on first one there will be decision
    // for min and max heap
    vector<int> ans;
    while(!maxHeap.empty()){
        ans.push_back(maxHeap.top() + x);
        maxHeap.pop();
    }

    return ans;
}

int main(){
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3, x = 7;
    vector<int> ans = kClostestNumber(arr, k, x);
    for(int it: ans){
        cout<<it<<" ";
    }
    return 0;
}