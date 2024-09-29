// permutation with spaces
// input output method

// input: abc
// output: 
// a_b_c
// ab_c
// a_bc
// abc

#include<iostream>
using namespace std;

// main decision tree was formed on the '_';
void printPattern(string s, string res){
    if(s.length() == 0){
        cout<<res<<endl;
        return;
    }

    // we are taking '_' in this branch
    string res_1 = res + '_' + s[0];
    // we are not taking '_' in this branch
    string res_2 = res + s[0];
    s.erase(0, 1);

    printPattern(s, res_1);
    printPattern(s, res_2);
}

int main(){
    string s = "abc";
    string initial = "";
    
    if(s.length() == 0) return;
    
    initial+=s[0];
    printPattern(s.erase(0,1), initial);
}