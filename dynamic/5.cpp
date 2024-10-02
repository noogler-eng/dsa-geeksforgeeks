// climbing up the stairs
// using dp memorization
#include<iostream>
#include<vector>
using namespace std;

// time complexity is o(n)
// space complexity is o(2n)
int noOfWaysToClimbStairs(int n, vector<int> store){
    if(n == 0 || n == 1) return store[n];

    if(store[n] != -1) return store[n];
    return store[n] = noOfWaysToClimbStairs(n-1, store) + noOfWaysToClimbStairs(n-2, store);
}

int main(){
    int n = 4;
    vector<int> store(n+1, -1);
    store[0] = 0;
    store[1] = 1;
    int ans = noOfWaysToClimbStairs(n, store);
    cout<<ans<<endl;
    return 0;
}