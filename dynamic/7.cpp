// shortcut - 
// 1. try to represent the prblem in terms of index
// 2. do all the possible stuffs acc to given in questions, do all the possible on that step / index
// 3. sum of stuffs, max, min .... of all

// frog jump - tabulisation method
#include<iostream>
#include<vector>
// we have to find the minimum energy it requires
using namespace std;
// time compelxity is o(n)
// space complexity is o(n)
int miniEnergyJumps(vector<int> energyStairs){

    int n = energyStairs.size();
    vector<int> miniEnergy(n); 
    
    miniEnergy[0] = 0;
    miniEnergy[1] = abs(energyStairs[1] - energyStairs[0]);

    for(int i=2; i< miniEnergy.size() + 1; i++){
        int jump1 = abs(energyStairs[i] - energyStairs[i-1]) + miniEnergy[i-1];
        int jump2 = abs(energyStairs[i] - energyStairs[i-2]) + miniEnergy[i-2];
        miniEnergy[i] = min(jump1, jump2);
    }

    // we have to ckeck for last stage
    return miniEnergy[n-1];
}

int main(){
    vector<int> energyStairs = {10, 20, 30, 10};
    int ans = miniEnergyJumps(energyStairs);
    cout<<ans<<endl;
    return 0;
}

// here greedy way will not work
// no greedy, use recurssion