// tabulation -> bottom up
// memorization -> top down, here we are memorizing the things

// memorization approach
#include<iostream>
#include<vector>
using namespace std;
// returning the nth fibo number
// num1
// num2
// num3 = num1 + num2
// 0 1 1 2 3 5 8 13 ...

// space complexity is o(n) + o(n)  -> recrssion space + vector space
// time compleity is o(n)
int fibonacciNumber(int n, vector<int> v){
    if(n == 0 || n == 1) return v[n];

    if(v[n] != -1) return v[n];

    // there are overlapping so dp will be applicable
    return v[n] = fibonacciNumber(n-1, v) + fibonacciNumber(n-2, v);
    // at last it will return here when finding the sum of all
}

int main(){
    // we are taking 0 based indexing
    int n = 5;
    vector<int> v(n+1, -1);
    v[0] = 0;
    v[1] = 1;
    int ans = fibonacciNumber(n, v);
    cout<<ans<<endl;
    return 0;
}