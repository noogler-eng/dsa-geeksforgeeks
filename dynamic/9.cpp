// forg k jums minimum energy
// we are allowing to jumps until k steps
#include<iostream>
#include<vector>
using namespace std;

// we are using simple recurssion
// this is medium level question of both recurssion and dp
// time complexity is o(n * k)
// space complexuty is o(n) as recursion stack space
int minEnergy(vector<int> &jumsArray, int k, int index){
    // means no jump we can take
    if(k == 0 || index == 0 || k >= jumsArray.size()) return 0;

    // jumping 1 step back
    // how we can maintain the constraint here so that it will not be out of bound
    int mini = INT_MAX;
    // monitoring the constraint
    for(int i=1; i<=k && index-i >= 0; i++){
        int energyOfJump = minEnergy(jumsArray, k, index-i) + abs(jumsArray[index] - jumsArray[index-i]);
        mini = min(mini, energyOfJump);
    }

    return mini;
}

int main(){
    vector<int> jumsArray = {10, 20, 30, 10};
    int ans = minEnergy(jumsArray, 3, jumsArray.size()-1);
    cout<<ans<<endl;
    return 0;
}