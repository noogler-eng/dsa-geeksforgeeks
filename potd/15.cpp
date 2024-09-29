#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int count = 0, maxCount = 0;
        
        // a person can jump from current building to next building only if 
        // when h(next building) > h(curr building)
        for(int i=0; i<arr.size() - 1; i++){
            if(arr[i] < arr[i + 1]){
                count++;
                maxCount = max(count, maxCount);
            }else{
                // if the person cannot jump then again start from 0
                count = 0;
            }
        }
        return maxCount;
    }
};