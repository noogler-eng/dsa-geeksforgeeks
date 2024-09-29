// Kth symbol in grammer
#include<iostream>
#include<math.h>
using namespace std;

// int n an k is given
// for value of n its depend on (n-1)th row

// this is how pattern will be formed
// In each row there is 2^n-1 elements
// k is opposite of its k%n-1 if k > (2^n-1) / 2;
// k is same as of above if is <= (2 ^ n-1) / 2;
// 0                    n = 1  
// 0 1                  n = 2
// 0 1 1 0              n = 3
// 0 1 1 0 1 0 0 1      n = 4       
// .....

// for (n, k) => 
int findSymbol(int n, int k){
    if(n == 1 && k == 1) return 0;

    // if k is greated the half
    // if k is less the half
    if( k > pow(2, n-2)){
        // here its depend on 
        if(findSymbol(n-1, k - (pow(2, n-2))) == 1){
            return 0;
        }else{
            return 1;
        }
    }else{
        return findSymbol(n-1, k);
    }


}

int main(){
    // in question n is starting from 1 and k is also from 1
    int n = 4, k = 7;
    int requiredSymbol = findSymbol(n, k);
    cout<<requiredSymbol<<endl;
    return 0;
}