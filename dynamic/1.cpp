// dynamic programming (enhanced recurssion)
// Intro, Identification
// top down approach -> table method

// Identification: 
// 1. choices like include or not, overlapping recursion -> dp, not solving again the smae thing
// 2. optimal things are asked like minimum, maximum, largest ....

// 0-1 knapsacks
// types of knapsacks 
// fractional knapsack - here we can fill bags in fractional quantity also
// bounded knapsack - wt of the bag is bounded, Max wt is given
// unbounded knapsack

// simillar problems on knapsacl
// 1. subset sum
// 2. equal sum partiton
// 3. count of subset sum
// 4. minimum subset sum diff
// 5. target sum
// 6. no of subset with given diff


// 0-1 knapsacks
#include<iostream>
#include<vector>
using namespace std;

// we hve to maximise the proft
// DB => topdown -> dp

// choice diagram
// wt = [1, 3, 4 ,5]

// simple recursion is used for this knapsack problem
int knapsack(vector<int> wt, vector<int> val, int W, int MaxProft, int index){
    // Base condition
    if(index == val.size()) return MaxProft;
    
    // choice decision
    if(wt[index] <= W){
        return max(knapsack(wt, val, W-wt[index], MaxProft+ val[index], index+1), knapsack(wt, val, W, MaxProft, index + 1));
    }else{
        return max(MaxProft, knapsack(wt, val, W, MaxProft, index+1));
    }
}

int main(){
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};

    // at max bag can hold this W weight
    // bounded knapsack
    int W = 7;
    int ans = knapsack(wt, val, W, 0, 0);
    cout<<ans<<endl;
    return 0;
}