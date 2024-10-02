// fibonacci in tablualtion method
#include<iostream>
#include<vector>
using namespace std;

// time complexity is o(n) and space complexity is o(n)
int tabulationMethod(int n){
    // starting with zero base indexing
    if(n == 0 || n == 1) return n;
    
    vector<int> store(n+1);
    store[0] = 0;
    store[1] = 1;
    // simmillar stuff, making an table
    for(int i=2; i<n+1; i++){
        store[i] = store[i-1] + store[i-2];
    }

    return store[n];
}
int main(){
    int n = 5;
    int ans = tabulationMethod(n);
    cout<<ans<<endl;
    return 0;
}

// we can also remove this space complexity to o(1)
// by taking curr, prev, pprev ...
