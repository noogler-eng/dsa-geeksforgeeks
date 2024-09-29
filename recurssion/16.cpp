// print N digit binary number having 1s > 0s in its prefixes
// input: n = 5
// 11010 then prefixes of this in which number of 1 greater then number of 0

// means there is 5 space in wich we can fill either by 1 or 0
// printing that number in which its prefixes has always 1s greater then number of 0's
#include<iostream>
using namespace std;
void fillingSpace(int n,int ones, int zeroes, string res ){
    if( n == 0 ){
        cout<<res<<endl;
        return;
    }

    if(ones >= zeroes){
        if(ones > zeroes){
            string res_1 = res + '0'; 
            fillingSpace(n-1, ones, zeroes + 1, res_1);
        }
        
        // never userd ones++ or zeroes++ in recursion or any liek ++ones or ++zeroes, this creates all mess
        string res_2 = res + '1'; 
        fillingSpace(n-1, ones + 1, zeroes, res_2);
    }
}

int main(){
    int n = 5;
    fillingSpace(n,0 , 0, "");
    return 0;
}