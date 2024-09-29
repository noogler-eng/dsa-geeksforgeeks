#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;

// SJF - it is an algo in which jobs are execiting in order of lowest ececution time
// we have to find the average waiting time = summantions of all waiting time / all 
int shortestJobFirst(vector<int> &bt){
    // assume all task comes together
    sort(bt.begin(), bt.end());

    // {1, 2, 3, 4, 7}
    // 0 + 1 + 3 .... 

    int upTillWaitingTime = 0;
    int totalAverageTime = 0;
    int i=0;
    while(i < bt.size()){
        totalAverageTime = totalAverageTime + upTillWaitingTime;
        upTillWaitingTime += bt[i];
        i++;
    }

    return totalAverageTime / bt.size();
}

int main(){
    vector<int> bt = {4, 3, 7, 1, 2};
    int averageWaitingTime = shortestJobFirst(bt);
    cout<<averageWaitingTime<<endl;
    return 0;
}