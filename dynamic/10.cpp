// forg k jums minimum energy
// we are allowing to jumps until k steps
#include<iostream>
#include<vector>
using namespace std;

// we are using tabluation
// space optimization if from o(n) -> o(1)
// time compelxity is o(n) * o(k)
// in table for every level we only require last k values
int minEnergy(vector<int> &jumsArray, int k, int index){
    
    int n = jumsArray.size();
    vector<int> store(n+1);
    store[0] = 0;
    
    for(int i=1; i<n+1; i++){
        int mini = INT_MAX;
        for(int j=1; j<=k && i-j>=0; j++){
            // jump of energy from taht level + diff of energy (curr jump)
            int step = store[i-j] + abs(jumsArray[i] - jumsArray[i-j]);
            mini = min(step, mini);
        } 
        store[i] = mini;
    }

    return store[n-1];
}

int main(){
    vector<int> jumsArray = {10, 20, 30, 10};
    int ans = minEnergy(jumsArray, 3, jumsArray.size()-1);
    cout<<ans<<endl;
    return 0;
}