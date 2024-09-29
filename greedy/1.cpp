// Assign cookies 
// constraint - 
// 1. greed factor and size of cookies are given
// 2. child only satisfies when >= greed is given to him
// 3. only one slot can be given to one child
#include<iostream>
//#include<bits/stdc++.h>
#include<vector>
using namespace std;
int distribution(vector<int> &greed, vector<int> &cookies){
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int child = 0;
    int i=0;
    while(i < cookies.size() && child < greed.size()){
        if(cookies[i] >= greed[child]){
            // cookies are assigned
            // cookes assigned in a way so that minimum cookes are spent
            child++;
        }
        i++;
    }
    
    // returning no of child satifies;
    return child;
}

int main(){
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 2, 1, 2, 1, 3};
    int noOfChildSatifies = distribution(greed, cookies);
    cout<<noOfChildSatifies<<endl;
    return 0;
}

// time complexity is o(nlogn) * 2 + o(n)