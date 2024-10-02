// climbing the nth stairs 
// this can be done using tabulization method

#include<iostream>
#include<vector>
using namespace std;
// time complexity is o(n)
// space complexity is o(n)
int noOfWaysToClimbStairs(int n){
    if(n == 0 || n == 1) return n;

    vector<int> store(n+1);
    store[0] = 0;
    store[1] = 1;
    
    for(int i=2; i<n+1; i++){
        store[i] = store[i-1] + store[i-2];
    }

    return store[n];
} 

int main(){
    int n = 4;
    vector<int> store(n+1, -1);
    store[0] = 0;
    store[1] = 1;
    int ans = noOfWaysToClimbStairs(n);
    cout<<ans<<endl;
    return 0;
}