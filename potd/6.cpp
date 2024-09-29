#include<iostream>
using namespace std;

// n stairs (recurssion)
// person at bottom of of stair want to reach at the top most 
// constraint: he can climb 1 steps or 2 steps at a time
// we have to count the number of ways to climb stairs

// this is very simmillar to fibaonacci series
int nStairs(int n){
    if(n == 1 || n == 2){
        return n;
    }

    return nStairs(n-1) + nStairs(n-2);
}

int main(){
    int n = 3;
    int noOfWays = nStairs(n);
    cout<<noOfWays<<endl;
    return 0;
}
