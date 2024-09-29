// missing and repeating
#include<iostream>
#include <cmath> // For abs
#include<vector>
using namespace std;

// input: [1, 3, 4, 3, 5]
// output [3, 2]

// method - sorting - o(nlogn) and o(1)
// method - another boolean array - o(n) and o(n)
// method - 

vector<int> findMissingRepeating(vector<int> &arr){

    int duplicate = -1;
    int n = arr.size();
    
    for(int i=0; i<n; i++){
        int index = abs(arr[i]) - 1;
        
        if(arr[index] < 0){
            duplicate = abs(arr[i]);
            break;
        }else{
            arr[index] = -arr[index];
        }
    }

    int sum = n * (n + 1)/2;
    int localSum = 0;
    for(int i=0; i<n; i++){
        localSum+=abs(arr[i]);
    }

    int missing = abs(sum - (localSum - duplicate));
    vector<int> ans;
    ans.push_back(duplicate);
    ans.push_back(missing);

    return ans;
}
int main(){
    vector<int> arr = {1, 3, 4, 3, 5};
    vector<int> ans = findMissingRepeating(arr);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}