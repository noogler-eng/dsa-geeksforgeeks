// Sum of elements
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int sumBetweenK1AndK2(vector<int> arr, int k1, int k2){

    priority_queue<int> maxHeap;
    for(int i=0; i<arr.size(); i++){
        maxHeap.push(arr[i]);
    }

    int sum1 = 0;
    int sum2 = 0;
    while(!maxHeap.empty()){
        if(maxHeap.size() <= k1){
            sum1+=maxHeap.top();
        }
        if(maxHeap.size() <= k2){
            sum2+=maxHeap.top();
        }
        maxHeap.pop();
    }

    return abs(sum1 - sum2);
}

int main(){
    vector<int> arr = {1, 3, 12, 5, 15, 11};
    // this are the k1th smallest and k2th smallest, means maxHeap;
    // arr sort = {1, 3, 5, 11, 12, 15}
    // 11 + 12 + 15 = 38
    int k1 = 3;
    int k2 = 6;
    int ans = sumBetweenK1AndK2(arr, k1, k2);
    cout<<ans<<endl;
    return 0;
}