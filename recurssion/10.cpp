// printing all the subsquence 
// subsequence is the smae order may be continous or may not be string ot array

#include<iostream>
using namespace std;

// this is two set type of problems in which we have two types of ways or decisison
void allSubsqueuceInAscendingOrder(string s, string res, int n){
    if( n == s.length() ){
        cout<<res<<endl;
        return;
    }

    string res_1 = res + s[n];
    string res_2 = res;
    allSubsqueuceInAscendingOrder(s, res_1, n+1);
    allSubsqueuceInAscendingOrder(s, res_2, n+1);
}


void allSubsqueuceInDescendingOrder(string s, string res, int n){
    if(n == -1){
        cout<<res<<endl;
        return;
    }

    // if selected and // if not selected
    string res_1 = res + s[n];
    string res_2 = res;

    allSubsqueuceInDescendingOrder(s, res_1, n-1);
    allSubsqueuceInDescendingOrder(s, res_2, n-1);
}



int main(){
    string s = "sharad";
    allSubsqueuceInDescendingOrder(s, "", s.length()-1);
    cout<<" -- "<<endl;
    allSubsqueuceInAscendingOrder(s, "", 0);
    return 0;
}