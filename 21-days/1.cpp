// given two strings in which remove those character from s1 which are present in s2
// both are different string and contains only lowercase

#include<iostream>
#include<unordered_map>
using namespace std;
string removeChar(string s1, string s2) {
    // input: cat and computer => output: ompuer
    unordered_map<char, int> m;
    string new_string = "";
    for(int i=0; i<s2.length(); i++){
        m[s2[i]] = 1;
    }

    for(int i=0; i<s1.length(); i++){
        if(m.find(s1[i]) == m.end()){
            new_string+=s1[i];
        }
    }
    
    return new_string;
}

int main(){
    string s1 = "computer";
    string s2 = "cat";

    string ans = removeChar(s1, s2);
    cout<<ans<<endl;
    return 0;
}