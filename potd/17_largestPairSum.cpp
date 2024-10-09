// Find the largest pair sum in an array of distinct integers.

// Input: arr[] = [12, 34, 10, 6, 40]
// Output: 74
// Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74

// Input: arr[] = [10, 20, 30]
// Output: 50
// Explanation: 20 + 30 = 50.

#include<iostream>
using namespace std;
class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int max1 = 0;
        int max2 = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }else if(arr[i] > max2){
                max2 = arr[i];
            }else{
                continue;
            }
        }
        return max1 + max2;
    }
};