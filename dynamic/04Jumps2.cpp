// forg k jums minimum energy
// we are allowing to jumps until 1 or 2 steps
#include<iostream>
#include<vector>
using namespace std;

// we are using simple recurssion
int minEnergy(vector<int> &jumsArray, int k, int index){
    // means no jump we can take
    if(k == 0 || index == 0) return 0;

    // jumping 1 step back
    int firstJump = minEnergy(jumsArray, k, index-1) + abs(jumsArray[index] - jumsArray[index-1]);
    if(index > 1){
        int secondJump = minEnergy(jumsArray, k, index-2) + abs(jumsArray[index] - jumsArray[index-2]);
        return min(firstJump, secondJump);
    }

    return firstJump;
}

int main(){
    vector<int> jumsArray = {10, 20, 30, 10};
    int ans = minEnergy(jumsArray, 3, jumsArray.size()-1);
    cout<<ans<<endl;
    return 0;
}