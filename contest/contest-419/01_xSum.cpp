// 
// here we have to find the freq
// keeping the x most freq element
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int xSum(vector<int> arr, int start, int k, int x){
    
    unordered_map<int, int> ma;
    priority_queue<pair<int, int>> m;

    for(int i=start; i<start+k; i++){
        ma[arr[i]]++;
    }

    for(auto i: ma){
        // sorting will depend on i.second that's why we write it first
        m.push({i.second, i.first});
    }

    int i = 0;
    int x_sum = 0;
    while(i < x && !m.empty()){
        x_sum+=m.top().first * m.top().second;
        m.pop();
        i++;
    }

    return x_sum;
}

int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;
    vector<int> ans;
    // for each subaaray of length k
    for(int i=0; i<=nums.size()-k; i++){
        ans.push_back(xSum(nums, i, k, x));
    }

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}