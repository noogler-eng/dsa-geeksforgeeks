// maximum sum of non adjacent elements in tables
// sum of subsequnce in that no two adjacent elemnt will occour
// arr: [1, 2, 4]
#include<iostream>
#include<vector>
using namespace std;
// tabluation maethod of dp
int getSum(vector<int> arr, int part1, int part2, int index){
    if(index > arr.size()) return max(part1, part2);

    // even indexing
    if(index % 2 == 0){
        // on selecting
        return getSum(arr, part1+arr[index], part2, index+1);
        // on not selecting
        return getSum(arr, part1, part2, index+1);
    }else{
        // odd indexing
        // on selecting
        return getSum(arr, part1, part2+arr[index], index+1);
        // on not selecting
        return getSum(arr, part1, part2, index+1);
    }
}
int main(){
    vector<int> arr = {1, 2, 4};
    int ans = getSum(arr, 0, 0, 0);
    cout<<"ans: "<<ans<<endl;
    return 0;
}