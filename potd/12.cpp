// facing the sun
//Given an array height representing the heights of buildings. 
// You have to count the buildings that will see the sunrise 
// (Assume the sun rises on the side of the array starting point).
// Note: The height of the building should be strictly greater than the height of the 
// buildings left in order to see the sun.

#include<iostream>
#include<vector>
using namespace std;
int countSunFacing(vector<int> &height){
    int maxi = 0, count = 0;
    for(int i=0; i<height.size(); i++){
        if(height[i] > maxi){
            count++;
            maxi = max(maxi, height[i]);
        }
    }
    return count;
}

int main(){
    vector<int> height = {7, 4, 8, 2, 9};
    int ans = countSunFacing(height);
    cout<<ans<<endl;
    return 0;
}
