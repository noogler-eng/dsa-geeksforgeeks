#include<iostream>
#include<vector>
using namespace std;

// missing in array
// array contains n-1 elements and it contains from 1 to n elements 
// time complexity o(n)
// space complexity o(n)

// we can do xor also 
// as y ^ y = 0
// as y ^ x = y

// [1 ^ 2 ^ 3 ^ 4 ^ 5] ^ [1 ^ 2 ^ 3 ^ 5]
// 0 ^ 0 ^ 0 ^ 4 ^ 0 -> 4

int findMissing(vector<int> &arr, int n){
    
    int miss, sum=0;
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
    }

    int originalSum = n * (n + 1) / 2;
    miss = originalSum - sum;
    return miss;
}

int main(){
    vector<int> arr = {1, 2, 3, 5};
    int n = 5;
    int ans = findMissing(arr, n);
    cout<<ans<<endl;
    return 0;
}