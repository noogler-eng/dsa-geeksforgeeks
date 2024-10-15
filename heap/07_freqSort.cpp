// sorting an array based on frequency
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> sortFreq(vector<int> arr){
    unordered_map<int, int> m;
    for(int i=0; i<arr.size(); i++) m[arr[i]]++;
    
    priority_queue<pair<int, int>> maxHeap;
    for(auto it: m){
        maxHeap.push({it.second, it.first});
    }

    vector<int> ans;
    while(!maxHeap.empty()){
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 1, 1, 3, 2, 2, 4, 5, 7, 5, 5};
    vector<int> ans = sortFreq(arr);
    for(int it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}