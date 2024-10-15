// finding the top k freq numbers
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> topKFreqNum(vector<int> arr, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        m[arr[i]]++;
    }

    for(auto it: m){
        minHeap.push({it.second, it.first});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 1, 1, 3, 2, 2, 4, 5, 7, 5, 5};
    int k = 3;
    vector<int> ans = topKFreqNum(arr, k);
    for(int it: ans){
        cout<<it<<endl;
    }

    return 0;
}