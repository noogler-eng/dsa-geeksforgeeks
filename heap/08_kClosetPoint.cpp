// k closest point to the origin
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>> kClosestPoint(vector<pair<int, int>> arr, int k){
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    vector<pair<int, int>> ans;
    for(int i=0; i<arr.size(); i++){
        int dist = pow(arr[i].first, 2) + pow(arr[i].second, 2);
        maxHeap.push({dist, {arr[i].first, arr[i].second}});
        
        if(maxHeap.size() > k) maxHeap.pop();
    }

    while(!maxHeap.empty()){
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return ans;
}

int main(){
    vector<pair<int, int>> arr = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    vector<pair<int, int>> ans = kClosestPoint(arr, k);
    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}