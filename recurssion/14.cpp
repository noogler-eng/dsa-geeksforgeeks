// letter case change problem
// input: a1B2
// output: a1b2, A1b2, a1B2, A1B2

#include<iostream>
using namespace std;

// it is not genral form
// here we are handling 2 char at a time
void getPermutateSame(string s, string res){
    if( s.length() == 0 ){
        cout<<res<<endl;        
        return;
    }

    // this will only valid when we have same pattern like alpha + num .., even number
    string res_1 = res + char(toupper(s[0])) + s[1];
    string res_2 = res + char(tolower(s[0])) + s[1];
    s.erase(0,2);

    getPermutateSame(s, res_1);
    getPermutateSame(s, res_2);
}

// this will work for all pattern as it is in generalised formed
// here we are handling one char at a time
void getPermutateDiff(string s, string res){
    if( s.length() == 0 ){
        cout<<res<<endl;        
        return;
    }

    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')){
        string res_1 = res + char(toupper(s[0]));
        string res_2 = res + char(tolower(s[0]));
        s.erase(0, 1);

        getPermutateDiff(s, res_1);
        getPermutateDiff(s, res_2);
    }else{
        string res_1 = res + s[0];
        s.erase(0, 1);
        getPermutateDiff(s, res_1);
    }
}

int main(){
    string s = "a1B2";
    getPermutateSame(s, "");
    return 0;
}

