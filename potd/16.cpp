// searching the target from the 2d matrix
// time complexity is o(log(n+m))
// space complexity is o(1)

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        
        int row = arr.size() - 1;
        int col = 0;
        while(row >= 0 && col < arr[0].size()){
            if(arr[row][col] == target){
                return true;
            }else if(arr[row][col] > target){
                row--;
            }else{
                col++;
            }
        }

        return false;
    }
};