// maximum sum of non adjacent elements in tables
// sum of subsequnce in that no two adjacent elemnt will occour
// arr: [1, 2, 4]
#include<iostream>
#include<vector>
using namespace std;
// tabluation maethod of dp
int getSum(vector<int> arr){
    int n = arr.size();
    vector<int> store(n+1);
    store[0] = 0;
    store[1] = arr[0];

    // there are subsequence that's why we are only checking back array of that number
    for(int i=2; i<n+1; i++){
        // on selecting, element is taken then sum will increase
        int selectSum = store[i-2] + arr[i-1]; 
        // on not selecting, element is not count
        int notSelectedSum = store[i-1];
        store[i] = max(selectSum, notSelectedSum);
    }
    
    for(int i=0; i<store.size(); i++){
        cout<<store[i]<<" ";
    }
    cout<<endl;

    return store[n];
}

int main(){
    vector<int> arr = {1, 2, 4};
    int ans = getSum(arr);
    cout<<"ans: "<<ans<<endl;
    return 0;
}