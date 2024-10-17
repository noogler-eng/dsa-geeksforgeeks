// connect the rope
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int connectRopes(vector<int> arr){
    // connecting the rope of minmum one first
    // taking minHeap
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i=0; i<arr.size(); i++){
        minheap.push(arr[i]);
    }

    int ans = 0;
    while(minheap.size() > 1){
        int top1 = minheap.top();
        minheap.pop();
        int top2 = minheap.top();
        minheap.pop();

        int sum = top1 + top2;
        ans+=sum;
        minheap.push(sum);
    }

    // we dont consider last element
    // as we need cost to join not joined rope value, we need cost only to make final rope

    return ans;
}

// here cost and arr are same
// 1, 2, 3, 4, 5
// 1 + 2 = 3
//         3 + 3 = 6
//                 4 + 6 = 10
// ..... 
// total cost = 3 + 6 + 10 ....
// greedy - 
// 1, 2, 3, 4, 5
// 1 + 2 = 3
// 3 + 3 = 6 due
// 4 + 5 = 9
// 9 + 6 = 15
// ans = 3 + 6 + 9 + 15 = 33
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int ans = connectRopes(arr);
    cout<<ans<<endl;
    return 0;
}
