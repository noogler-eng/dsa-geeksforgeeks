// permutation with case change

#include<iostream>
using namespace std;

// input: ab
// output: ab, Ab, aB, AB
//          ab 
//       a      A
//     ab  aB|Ab  Ab  

void makingCases(string s, string res){
    if( s.length() == 0 ){
        cout<<res<<endl;
        return;
    }

    string res_1 = res + char(tolower(s[0]));
    string res_2 = res + char(toupper(s[0]));
    s.erase(0, 1);
    makingCases(s, res_1);
    makingCases(s, res_2);
}

int main(){ 
    string str = "ab";
    makingCases(str, "");
    return 0;
}